#ifndef	BSTREE_H
#define	BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T>
class BSTree{
	
	private:
		int nelem;
		BSNode<T>* root;

	public:
		//Creación y tamaño
		BSTree(){
			nelem = 0;
			root = nullptr;
		}
		int size() const{
			return nelem;
		}
		
		//Búsqueda de elementos
		T search(T e) const{
			return search(root, e)->elem;
		}
		T operator[](T e) const{
			return search(e);
		}

	private:
		BSTree<T>* search(BSNode<T>* n, T e){
			if (n == nullptr){
				throw std::runtime_error("No se ha encontrado el elemento");
			}
			if (e < n->elem){
				return search(n->left, e);
			}
			if (e > n->elem){
				return search(n->right, e);
			}
			return n;
		}
	
	public:
		//Inserción de elementos
		void insert(T e){
			root = insert(root, e);
			nelem++;
		}

	private:
		BSNode<T>* insert(BSNode<T>* n, T e){
			if (e == n->elem){
				throw std::runtime_error("El elemento ya se encuentra en el árbol.");
			}
			if (n == nullptr){
				return new BSNode(e);
			}
			if (e < n->elem){
				n->left = insert(n->left, e);
			}else{
				n->right = insert(n->right, e);
			}
			return n;
		}

	public:
		//Recorrido e impresión del árbol
		friend std::ostream& operator<<(std::ostream& out, const BSTree<T>& bst){
			return print_inorder(out, bst.root);
		}

	private:
		void print_inorder(std::ostream& out, BSNode<T> n) const{
			if (n != nullptr){
				print_inorder(out, n->left);
				out<<n<<", ";

				if (n->right != nullptr){
					print_inorder(out, n->right);
				}
			}
		}

	public:
		//Eliminación de elementos
		void remove(T e){
			root = remove(root, e);
			nelem--;
		}

	private:
		BSNode<T>* remove(BSNode<T>* n, T e){
			if (n == nullptr){
				throw std::runtime_error("No se ha encontrado el elemento");
			}
			if (e < n->elem){
				n->left = remove(n->left, e);
			}else{
				if (e > n->elem){
					n->right = remove(n->right, e);
				}else{
					if (n->left != nullptr && n->right != nullptr){
						n->elem = max(n->left);
						n->left = remove_max(n->left);
					}else{
						n = (n->left != nullptr)? n->left : n->right;
					}
				}
			}
			return n;
		}
		T max(BSNode<T>* n) const{
			if (n == nullptr){
				throw std::runtime_error("No se ha encontrado el elemento");
			}
			if (n->right != nullptr){
				return max(n->right);
			}
			return n->elem;
		}
		BSNode<T>* remove_max(BSNode<T>* n){
			if (n->right == nullptr){
				return n->left;
			}
			n->right = remove_max(n->right);
			return n;
		}
	
	public:
		//Destrucción
		~BSTree(){
			delete_cascade(root);
		}

	private:
		void delete_cascade(BSNode<T>* n){
			if (n != nullptr){
				if (n->left != nullptr){
					delete_cascade(n->left);
				}
				if (n->right != nullptr){
					delete_cascade(n->right);
				}
				delete* n;
			}
		}
};

#endif
