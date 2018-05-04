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

int main(){
	int t;
	bst<int,int> three;
	three.insert(1,1);
	three.insert(2,5);
	three.insert(3,4);
	three.print();
	three.remove(2);
	cout<<endl;
	three.print();
	cout<<endl;
	t=numArboles(4);
	cout<<t;
	cout<<endl;

	cout<<"HOLI"<<endl;
	return 0;
}