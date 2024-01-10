#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "/home/tomas/pract1/PRA_2324_P1/ListLinked.h"

template <typename V>
class HashTable: public Dict<V>{
	
	private:
		int n;
		int max;
		ListLinked<TableEntry<V>>* table;
	
	public:
		//Métodos de Dict.h
		void insert(std::string key, V value) override{
			try{
				search(key);
			}catch(std::runtime_error& e){
				int NumCubeta = h(key);
				table[NumCubeta].prepend(TableEntry<V>(key, value));
				n++;

				return;
			}
			
			throw std::runtime_error("la clave ya se encuentra en el diccionario.");
		}
		V search(std::string key) override{
			int NumCubeta = h(key);

			for(int i = 0; i < table[NumCubeta].size(); i++){
				
				if(key == table[NumCubeta].get(i).key){

					return table[NumCubeta].get(i).value;
				}
			}

			throw std::runtime_error("No se encontró la clave.");
		}
		V remove(std::string key) override{
			int NumCubeta = h(key);

			for(int i = 0; i < table[NumCubeta].size(); i++){
				
				if(key == table[NumCubeta].get(i).key){
					TableEntry<V> aux = table[NumCubeta].remove(i);
					n--;

					return aux.value;
				}
			}
		}
		int entries() override{
			return n;
		}

		//Métodos propios
	private:
		int h(std::string key){
			int suma = 0;

			for(int i = 0; i < key.size(); i++){
				suma += int(key.at(i));
			}

			return suma % max;
		}
	public:
		HashTable(int size){
			this->n = 0;
			this->max = size;
			table = new ListLinked<TableEntry<V>>[size]();
		}
		~HashTable(){
			delete[] table;
		}

		int capacity(){
			return max;
		}
		friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &ht){
			out<<"HashTable ("<<ht.n<<" entradas, capacidad: "<<ht.max<<")"<<std::endl<<"{"<<std::endl;

			for(int i = 0; i < ht.max; i++){
				out<<"Cubeta "<<i<<" ["<<std::endl;

				for(int j = 0; j < ht.table[i].size(); j++){
					out<<std::endl<<"(Clave: "<<ht.table[i].get(j).key<<", Valor: "<<ht.table[i].get(j).value<<")";
				}
				out<<std::endl<<"]"<<std::endl;
			}
			out<<"}"<<std::endl;

			return out;
		}
		V operator[](std::string key){
			return search(key);
		}
};

#endif
