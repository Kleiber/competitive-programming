#include<iostream>
#include<map>
using namespace std;
int main(){
	map<char,double> M;
	M['W'] = 1.0     ; M['H'] = 1.0/2.0 ; M['Q'] = 1.0/4.0 ; 
	M['E'] = 1.0/8.0 ; M['S'] = 1.0/16.0; M['T'] = 1.0/32.0; 
	M['X'] = 1.0/64.0;
	string s;
	while(cin>>s){
		if(s == "*") break;
		int cont = 0;
		double suma = 0;
		string d = "";
		for(int i = 1; i < s.size(); i++){
			if(s[i] == '/'){
				if(suma == 1) cont++;
				suma = 0;
				d = "";
			}else{
				d+=s[i];
				suma += M[s[i]];
			}
		}
		cout<<cont<<endl;
	}
	return 0;
}