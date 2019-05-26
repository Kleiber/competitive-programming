#include<iostream>
#include<cmath>
using namespace std;
int main(){
	string s,c;
	string a = "", b ="";
	bool f = 1;
	cin>>s;
	cin>>c;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != '|'){
			if(f) a += s[i];
			else b += s[i];
		}else f = 0;
	}
	
	bool e = 0;
	int aux = abs(a.size() - b .size());
	
	for(int i = 0; i < c.size(); i++){
		if(a.size() > b.size()) b += c[i];
		else{
			if(a.size() < b.size()) a += c[i];
			else{
				if(a.size() == b.size()){
					if(e){
						a += c[i];
						e = 0;
					}else{
						b += c[i];
						e = 1;
					}
				}
			}
		}
	}
	
	if(a.size() == b.size()) cout<<a<<"|"<<b<<endl;
	else cout<<"Impossible"<<endl;
}