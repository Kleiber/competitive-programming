#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int cases,cont;
	cin>>cases;
	for(int i = 0; i < cases; i++){
		if(i != 0) cout<<endl;
		int n;
		double init,fin,c,acum = 0,ans;
		cin>>n;
		cin>>init>>fin;
		for(int i = n; i > 0; i--){
			cin>>c;
			acum += 2*i*c;
		}
		
		ans = ((double)n*init + fin - acum)/ (double)(n+1);
		printf("%.2f\n",ans);
	}
	
	return 0;
}