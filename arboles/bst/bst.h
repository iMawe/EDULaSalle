#ifndef BST_H
#define BST_H

#include <iostream>

template <class K,class V>
class bst;

template <class K,class V>
class node
{
private:
	K key;
    V value;
    int hgt;//Esta es la raíz de la altura del nodo del árbol
    unsigned int freq;
    node<K,V> * p_children[2];

public:
	node(const K k, const V v, node<K,V> * children=NULL);
	virtual ~node();

friend class bst<K,V>;
};

template <class K,class V>
class bst{
private:
	node<K,V> * root;
public:
	bst();
	virtual ~bst();

	int max(int a,int b){
		if(a<b){
			return b;
		}else{
			return a;
		}
	}

	bool find(K key);
	bool insert(K key, V value);

	void print(node<K,V> * n);
	void print();

	int altura(node<K,V> * n);
	int altura();

	void rotacionizq(node<K,V>** n){ 
		int hgt;
	    node<K,V>* k1; 
	    k1=(*n)->p_children[0]; 
	    (*n)->p_children[0]=k1->p_children[1]; 
	    k1->p_children[1]=*n; 
	    *n=k1;
	    (*n)->hgt=max(altura((*n)->p_children[0]),altura((*n)->p_children[1]))+1; 
	    k1->hgt=max(altura(k1->p_children[0]),altura((k1)->p_children[1]))+1; 
	}
	void rotacionder(node<K,V>** n){ 
		int hgt;
	    node<K,V>* k1; 
	    k1=(*n)->p_children[1]; 
	    (*n)->p_children[1]=k1->p_children[0]; 
	    k1->p_children[0]=*n; 
	    *n = k1;
	    (*n)->hgt=max(altura((*n)->p_children[0]),altura((*n)->p_children[1]))+1; 
	    k1->hgt=max(altura(k1->p_children[1]),altura((k1)->p_children[0]))+1; 
	}
	void doblerotacionizqui(node<K,V>** &k3){ 
	    rotacionder(&(*k3)->p_children[0]);
	    rotacionizq(k3);

	} 
	void doblerotaciondere(node<K,V>** &k3){ 
	    rotacionizq(&(*k3)->p_children[1]); 
	    rotacionder(k3); 
	}

	void remove(K key);//--->tarea

private:
	bool _find(node<K,V> **&tmp, K key);
	void removePri(node<K,V>** n,V x);
};

#include "bst.inl"

#endif