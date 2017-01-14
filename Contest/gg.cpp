#include<bits/stdc++.h>
using namespace std;
int f(int x,int y){
	double i;
	for( i = 1; i < x + 1; i++){
		if(((i+1)*(y - 0.00000001) + y*i) > x) break;
	}
	
	return i;
}

int main(){
	int w1,h1,w2,h2;
	while(cin>>w1>>h1>>w2>>h2){
		cout<<f(w1, w2)*f(h1, h2)<<endl;
	}	
	return 0;
}