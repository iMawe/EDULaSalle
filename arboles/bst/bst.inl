
using namespace std;

template<class K,class V>
node<K,V>::node(const K k,const V d,node<K,V> * children){
	key=k;
	value=d;
	hgt=0;
	freq=1;
	p_children[1]=NULL;
    p_children[0]=NULL;
}

template<class K,class V>
node<K,V>::~node(){
}

template<class K, class V>
bst<K,V>::bst(){
	root=NULL;
}
template<class K, class V>
bst<K,V>::~bst(){

}

template <class K, class V>
bool bst<K,V>::find(K keys){
	node<K,V> **aux;
    if(_find(aux,keys)==true){
        cout<<keys<<" encontrado"<<endl;
    }else{
        cout<<keys<<" no encontrado";
    }          
}


template <class K, class V>
bool bst<K,V>::insert(K keys, V value){
	node<K,V> **aux;
	if(_find(aux,keys)==false){
		(*aux)=new node<K,V>(keys,value);
	}
}

template <class K, class V>
void bst<K,V>::remove(K key){
	removePri(&root,key);
}//--->tarea

template <class K, class V>
void bst<K,V>::removePri(node<K,V>** n,V x){
	if(*n==NULL) return ;//No es encontrar el valor X de los nodos 
    if(x <(*n)->key) 
    { 
         removePri(&(*n)->p_children[0],x);//Si X es inferior al valor del nodo, sigue en el árbol de la izquierda elimina el nodo X 
         if(2==altura((*n)->p_children[1])-altura((*n)->p_children[0])) 
            if((*n)->p_children[1]->p_children[0]!=NULL&&(altura((*n)->p_children[1]->p_children[0])>altura((*n)->p_children[1]->p_children[1])) ){
                doblerotaciondere(n); 
                
            }
            else{
                rotacionder(n);
                
            }
    } 
 
    else if(x > (*n)->key) 
    { 
         removePri(&(*n)->p_children[1],x);//Si X es mayor que el valor del nodo, sigue en el nodo eliminar X subárbol 
         if(2==altura((*n)->p_children[0])-altura((*n)->p_children[1])) 
            if((*n)->p_children[0]->p_children[1]!=NULL&& (altura((*n)->p_children[0]->p_children[1])>altura((*n)->p_children[0]->p_children[0]) )) {
                doblerotacionizqui(n);
                
            }
            else{
                rotacionizq(n);
                
            }
    } 
 
    else//Si son iguales, el nodo es eliminar nodo 
    { 
        if((*n)->p_children[0]&&(*n)->p_children[1])//El nodo tiene dos hijos 
        { 
            node<K,V>* temp=(*n)->p_children[1];//Nodos hijo temp hacia la derecha 
            while(temp->p_children[0]!=NULL) temp=temp->p_children[0];//Encontrar un mínimo de nodos subárbol mediana 
            //A la derecha en el valor mínimo de nodos subárbol de asignar a este nodo 
            (*n)->key=temp->key; 
            (*n)->freq=temp->freq; 
            removePri(&(*n)->p_children[1],temp->key);//Eliminar nodos en el valor mínimo de la derecha subárbol 
            if(2==altura((*n)->p_children[0])-altura((*n)->p_children[1])) 
            { 
                if((*n)->p_children[0]->p_children[1]!=NULL&& (altura((*n)->p_children[0]->p_children[1])>altura((*n)->p_children[0]->p_children[0]) )){
                    doblerotacionizqui(n);
                     
                }
                else{
                    rotacionizq(n);
                     
                }
            } 
        } 
        else//El nodo tiene un hijo o 1 0 
        { 
            node<K,V>* temp=*n; 
            if((*n)->p_children[0]==NULL)//Hijo o no, el hijo de la derecha 
            (*n)=(*n)->p_children[1]; 
            else if((*n)->p_children[1]==NULL)//A la izquierda, hijo 
            (*n)=(*n)->p_children[0]; 
            delete(temp); 
           temp=NULL;
           
        } 
} 
    if(*n==NULL) return; 
    (*n)->hgt=max(altura((*n)->p_children[0]),altura((*n)->p_children[1]))+1; 
    return;
}//--->tarea



template <class K, class V>
void bst<K,V>::print(node<K,V> * nd){
	if(nd)
    {
        cout << nd->key <<"(";
        print(nd->p_children[0]);
        cout<<" , ";
        print(nd->p_children[1]);
        cout<<")";
    }
}

template <class K, class V>
void bst<K,V>::print(){
	print(root);
}

template <class K, class V>
bool bst<K,V>::_find(node<K,V> **&tmp, K keys){
	tmp=&root;
    while(*tmp){
	   
            if((*tmp)->key==keys){
                return true;
            }
            tmp=&(*tmp)->p_children[((*tmp)->key<keys)];
       }
    return false;
}

template <class K, class V>
int bst<K,V>::altura(node<K,V> * n){
	int Altura_dere=0;
	int Altura_izq=0;
	if(n==NULL){
		return 0;
	}else{
		Altura_dere=altura(n->p_children[1]);
		Altura_izq=altura(n->p_children[0]);
	return max(Altura_dere,Altura_izq)+1;	
	}
}

