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
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;
string base = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string mirror = "A***3**HIL*JM*O***2TUVWXY51SE*Z**8*";
bool existe(char c){
	int pos= base.find(c);
	if(mirror[pos] != '*' && pos != -1) return 1;
	else return 0;
}
bool ispalindrome(string c){
	string aux = c;
	reverse(c.begin(),c.end());
	return c == aux;
}
bool ismirrored(string c){
	string aux ="";
	int cont =0;
	for(int i = 0; i<c.size();i++){
		aux+=mirror[base.find(c[i])];
		if(existe(c[i])) cont++;
		else break;
	}
	reverse(aux.begin(),aux.end());
	if(cont == c.size() && aux == c) return 1;
	else return 0;
}
int main(){
	string c;
	while(cin>>c){
		int palindrome = ispalindrome(c);
		int mirrored = ismirrored(c);
		if(palindrome&& mirrored)  cout<<c<<" -- is a mirrored palindrome."<<endl;
		else
			if(palindrome) cout<<c<<" -- is a regular palindrome."<<endl;
			else
				if(mirrored) cout<<c<<" -- is a mirrored string."<<endl;
				else cout<<c<<" -- is not a palindrome."<<endl;
		
		printf("\n");
	}
return 0;
}
