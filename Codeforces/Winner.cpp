#include <iostream>
#include <vector>
#include <utility>
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
#include<stdio.h>
#include<string.h>
using namespace std;
int main() {
  int casos, puntos,mayor = -1000000000;
  string jugador;
  cin>>casos;
  map<string,int> M;
  map<string,int>::iterator it;
  queue< pair<string,int> >C;
  for(int i=0; i<casos; i++) {
    cin >> jugador >> puntos;
	
	C.push(make_pair(jugador,puntos));
    M[jugador]+=puntos;
  }
  
  for(it=M.begin();it!=M.end();it++) {
    mayor = max(mayor,(*it).second);
  }
  
  map<string, int> Aux;
  while(!C.empty()){
	string j = C.front().first;
	int p =C.front().second;
    Aux[j] += p;
    if(Aux[j]>=mayor && M[j]==mayor) {
      cout<< j<<endl;
      break;
    }
	C.pop();
  }
  
	return 0;
}