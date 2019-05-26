#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
	int a,aux,num = 0,den = 0;
	cin>>a;
	for(int i = 2; i <= a-1; i++){
		aux = a;
		while(aux >= i){
			//cout<<aux%i;
			num += aux % i;
			aux = aux/i;
		}
		num += aux;
		//cout<<aux%i<<endl;
		den++;
	}
	
	int gcd = __gcd(num,den);
	cout<<num/gcd<<"/"<<den/gcd<<endl;
	return 0;
}