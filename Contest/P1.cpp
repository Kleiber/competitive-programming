#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int x;
	cin>>x;
while(x--){
	int a;
	int b;
	cin>>b;
	cin>>a;
	while(a--){
	
	for(int j=1;j<=b;j++){
	int t=j;
	while(t--){
	cout<<j;
	}
	cout<<endl;}
	for(int j=b-1;j>=1;j--){
		int t=j;
		while(t--){
		cout<<j;
		}
		cout<<endl;
	}
		if(a!=0)cout<<endl;
	}
	if(x!=0)cout<<endl;
	}
	return 0;
}