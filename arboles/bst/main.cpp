#include <iostream>
#include "bst.h"
using namespace std;


int factorial(int n){
    if (n==0)
        return 1;
    else
         return n*factorial(n-1);
	}

int numArboles(int nodos){
		int t;
		t=(factorial(2*nodos))/(factorial(nodos+1)*factorial(nodos));
		return t;
	}
	
/*int numArboles2(int nodos){
		int t;
		for(int i=0; i<nodos; i++){
			t=
		}
	}*/

int main(){
	
	bst<int, float> tree;
	tree.insert(41, .43);
	tree.insert(20, .5454);
	tree.insert(65, .23);
	tree.insert(50, .4542);
	tree.insert(91, 43.5454);
	tree.insert(72, 3.23);
	tree.insert(99, 321.32);
	tree.print();
	cout<<endl;
	tree.remove(65);
	tree.print();
	cout<<endl;
	tree.insert(65,89);
	tree.print();
	/*cout<<endl;
	t=numArboles(4);
	cout<<t;
	cout<<endl;

	cout<<"HOLI"<<endl;*/
	return 0;
}