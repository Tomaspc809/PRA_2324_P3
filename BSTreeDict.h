#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>>* tree;

    public:
        //Métodos heredados de Dict.h
	void insert(std::string key, V value) override{
		tree->insert(TableEntry<V>(key, value));
	}
	V search(std::string key) override{
		return tree->search(TableEntry<V>(key)).value;
	}
	V remove(std::string key) override{
		V ret = tree->search(TableEntry<V>(key)).value;
		tree->remove(TableEntry<V>(key));

		return ret;
	}
	int entries() override{
		return tree->size();
	}
	//Métodos propios
	BSTreeDict(){
		tree = new BSTree<TableEntry<V>>();
	}
	~BSTreeDict(){
		delete tree;
	}
	friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bst){
		out<<*(bst.tree)<<std::endl;

		return out;
	}
	V operator[](std::string key){
		return search(key);
	}
};

#endif
