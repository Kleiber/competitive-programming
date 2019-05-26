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
using namespace std;
int main()
{
	string s;
	cin>>s;
	
	bool TodoMayuscula = 1;
	for(int i = 0; i < s.size() ; i++){
		if(islower(s[i]))
			TodoMayuscula =0;
	}
	//--si todo es mayuscula
	if(TodoMayuscula){
		//--convertimos todo a minuscula
		for(int i = 0; i < s.size() ; i++)
			s[i] = tolower(s[i]);
		cout<<s<<endl;
	}
	else{
		//--si el primero es minuscula y los demas mayusculas
		bool Primero = 1;
		if(isupper(s[0])) Primero = 0;
		
		for(int i = 1; i < s.size() ; i++){
			if(islower(s[i]))  Primero = 0;
		}
		
		if(Primero){
			s[0] = toupper(s[0]);
			for(int i = 1; i < s.size() ; i++)
				s[i] = tolower(s[i]);
			cout<<s<<endl;
		}
		else
			cout<<s<<endl;
	}
    return 0;
}