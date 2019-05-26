#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string.h>
#include<sstream>
#define MAX 1000000
using namespace std;
bool V[MAX];
void criba(){
	memset(V,true,sizeof(V));
	for(int i = 2; i < MAX; i++){
		if(V[i]){
			for(int j = 2*i; j < MAX; j+=i)
				V[j] = false;
		}
	}
}
int main(){
	criba();
	string n;
	while(cin>>n){
		string aux = n;
		stringstream n1(n);
		int a ; n1>>a;
		reverse(n.begin(),n.end());
		stringstream n2(n);
		int b ; n2>>b;
		
		if(a == b && V[a]) cout<<aux<<" is prime."<<endl;
		else
		{
			if(!V[a]) cout<<aux<<" is not prime."<<endl;
			else{
				if(V[a] && V[b]) cout<<aux<<" is emirp."<<endl;
				else{
					if(V[a]) cout<<aux<<" is prime."<<endl;
				}
			}
		}
	}
}
