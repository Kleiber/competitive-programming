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
using namespace std;
int main(){
	int casos;
	cin>>casos;
	while(casos--){
		int n;
		cin>>n;
		vector<string> V;
		for(int i = 0; i < n;i++){
			string s;
			cin>>s;
			V.push_back(s);
		}
		while(1){
			string s;
			cin>>s;
			if( s =="END")  break;
			int cont =0;
			cout<<"Anagrams for: "<<s<<endl;
			string aux=s;
			sort(aux.begin(),aux.end());
			
			for(int i = 0; i < V.size(); i++){
				string aux1 = V[i];
				sort(aux1.begin(),aux1.end());
				if(aux1 == aux){
					cout <<"  "<<cont + 1<<") "<<V[i]<<endl;
					cont++;
				}
			}
			if(cont == 0)
				cout<<"No anagrams for: "<<s<<endl;
		}
		
		if(casos != 0)
			cout<<endl;
	}
	return 0;
}