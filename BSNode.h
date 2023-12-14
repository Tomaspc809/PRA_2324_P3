#ifndef	BSNODE_H
#define	BSNODE_H

#include <ostream>

template <typename T>
class BSNode{
	
	public:
		T elem;
		BSNode<T>* left;
		BSNode<T>* right;

		BSNode(T elem){
			this->elem = elem;
			left = nullptr;
			right = nullptr;
		}
		friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn){
			out<<bsn.elem;
			return out;
		}
};

#endif
