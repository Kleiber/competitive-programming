#include<iostream>
#include<sstream>
using namespace std;
bool isnumber(char c){
	return (c - '0' >= 0 && c - '0' <= 9);
}

int main(){
	int n,caso = 1;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		cout<<"Case "<<caso<<": ";
		int ind = 0;
		char aux1;
		int aux2 = 0;
		bool flag  = 0;
		string num = "";
		for(int i = 0; i < s.size(); ){
			aux1 = s[i];
			i++;
			while(isnumber(s[i])){
				num += s[i];
				i++;
			}
	
			stringstream in(num);
			in>>aux2;
			for(int i = 0; i < aux2; i++) cout<<aux1;				
			aux2 = 0;
			num ="";
		}
		cout<<endl;
		caso++;
	}
	return 0;
}