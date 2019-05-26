#include<iostream>
#define MAX 1000
#define MIN 0
using namespace std;
int main(){
	int n,l,r,p = MAX,g = MIN;
	cin>>n;
	for(int i = 1; i <= n; i++){
		int aux;
		cin>>aux;
		if(aux <= p ) p = aux, r = i;
		if(aux > g) g = aux, l = i;
	}
	
	if(p == g) cout<<0<<endl;
	else{
		if(l < r) cout<<l + (n - r - 1)<<endl;
		else cout<<l + (n - r - 2)<<endl;
	}
	return 0;
}