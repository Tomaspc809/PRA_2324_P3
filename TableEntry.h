#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <iostream>

template <typename V>
class TableEntry
{
	public:
		//Atributos
		std::string key;
		V value;
		//Metodos
		TableEntry(std::string key, V value)
		{
			this->key = key;
			this->value = value;
		}
		TableEntry(std::string key)
		{
			this->key = key;
		}
		TableEntry()
		{
			key = "";
		}

		friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2)
		{
			if(te1.key == te2.key){
				return true;
			}
			return false;
		}
		friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2)
		{
			if(te1.key != te2.key){
				return true;
			}
			return false;	
		}
		friend bool operator<(const TableEntry<V> &te1, const TableEntry<V> &te2)
		{
			if(te1.key < te2.key){
				return true;
			}
			return false;	
		}
		friend bool operator>(const TableEntry<V> &te1, const TableEntry<V> &te2)
		{
			if(te1.key > te2.key){
				return true;
			}
			return false;	
		}
		friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te)
		{
			std::cout<<te.key<<" -> "<<te.value;

			return out;
		}
};
#endif
