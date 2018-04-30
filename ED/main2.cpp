#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

using namespace std;

bool balanced(string s){
	Stack<T> *p= new Stack<T>;
	for(int i=0; i<strlen(s);i++){
		if(s[i]=="(" or s[i]=="["){
			p.push(i);
		}
		else if(p.top=="("){
			p.pop();
			p.push(")");
			if (s[i]==p.top){
				p.pop();
			}
		}
		else if(p.top=="["){
			p.pop();
			p.push("]");
			if(s[i]==p.top){
				p.pop();
			}
		}
		else return false;
	}
	return isEmpty();
}

int main(){
	cout<<"hello world";
	return 0;
}