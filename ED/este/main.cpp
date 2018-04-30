#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

using namespace std;

/*template <class T>
bool balanced(T s){
	stack<T> *p= new stack<T>;
	for(int i=0; i<sizeof(s);i++){
		if(s[i]=="(" or s[i]=="["){
			p.push(i);
		}
		else if(p.top()=="("){
			p.pop();
			p.push(")");
			if (s[i]==p.top()){
				p.pop();
			}
		}
		else if(p.top()=="["){
			p.pop();
			p.push("]");
			if(s[i]==p.top()){
				p.pop();
			}
		}
		else return false;
	}
	return true;
}*/

/*
int minimo(){

}*/

int main(){
	cout<<"hello world";
	a="[(([]))]";
	balanced(a)
	return 0;
}