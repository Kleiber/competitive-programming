#include<iostream>
using namespace std;
int main(){
	string s;
	int i = 1;
	cin>>s;
	while(s != "*"){
		cout<<"Case "<<i<<": ";
		if(s == "Hajj") cout<<"Hajj-e-Akbar"<<endl;
		else cout<<"Hajj-e-Asghar"<<endl;
		i++;
		cin>>s;
	}
	return 0;
}