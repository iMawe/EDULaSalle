#include <iostream>
#include "bst.h"
using namespace std;
int main(){
	bst<int,int> three;
	three.insert(1,1);
	three.insert(2,5);
	three.insert(3,4);
	three.print();
	three.remove(5);
	cout<<endl;
	three.print();
	cout<<"HOLI"<<endl;
	return 0;
}