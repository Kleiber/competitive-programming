#include<iostream>
using namespace std;
int main(){
	long long int n, monto, sum = 0;
	string s;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>s;
		if(s == "donate"){
			cin>> monto;
			sum += monto;
		}
		else cout<<sum<<endl;
	}
	return 0;
}