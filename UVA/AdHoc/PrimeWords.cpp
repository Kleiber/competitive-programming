#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#define MAX 100000
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
	string s;
	while(cin>>s){
		int a = 0;
		for(int i = 0; i < s.size(); i++){
			int n = (int)s[i];
			a += n;
			if(s[i] >= 'A' && s[i] <= 'Z') a -= 38;
			else a -= 96;
		}
		
		if(V[a]) cout<<"It is a prime word."<<endl;
		else cout<<"It is not a prime word."<<endl;
	}
	return 0;
}