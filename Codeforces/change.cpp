#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>  
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct nodo{
    int v;
    nodo() {}
    nodo(int a){v = a;}
};
bool operator <(nodo a,nodo b){ return a.v > b.v;}

int main() {
	priority_queue<nodo> cola;
	int n,k,e,s = 0;
	cin>>n>>k;
	while(n-->0){ 
		cin>>e; 
		cola.push(nodo(e));
	}
	while(k-->0){
		e=cola.top().v;
		cola.pop();
		cola.push(nodo(-e));
	}
	while(cola.size()){
		s+=cola.top().v;
		cola.pop();
	}
	cout<<s<<endl;
	
	return 0;
}