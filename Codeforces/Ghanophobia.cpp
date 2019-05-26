#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	freopen("ghanophobia.in","r",stdin);
	int n;
	cin>>n;
	for(int j = 1; j <= n; j++){
		
		string s,aux ="";
		int e,g;
		cin>>s;
		
		for(int i = 0; i < s.size(); i++){
			if(s[i] == ':'){
				e = atoi(aux.c_str()) ;
				aux ="";
			}
			else aux += s[i];
		}
		
		g = atoi(aux.c_str());
		
		cout<<"Case "<<j<<": ";
		if(e == 5 && g == 0) cout<<"YES"<<endl;
		else{
			if(e + 1 == g + 6) cout<<"PENALTIES"<<endl;
			else{
				if(e + 1 > g + 6) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}

