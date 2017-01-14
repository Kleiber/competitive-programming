#include<bits/stdc++.h>
using namespace std;

struct node{
  char c;
  long long int p;
  map<char, node*> m;
  node(char _c){
    c = _c;
    p = 0;
  }
};

long long int N, T, casos;
string s;

int main(){
	cin>>T;
	casos = 1;
  
	while(T--){
		cin >> N;
		node* root = new node('\0');
		long long int sum = 0;
		
		for(int i = 0; i < N; i++){
		
			cin>>s;
			node* actual = root;
			
			for(int i = 0; i < s.size(); i++){
				if(actual -> m.find(s[i]) == actual -> m.end()){
					actual -> m[s[i]] = new node(s[i]);
				}
				
				actual = actual -> m[s[i]];
				(actual -> p)++;
			}
			
			
			int c = 1;
			int ant = 0;
			actual = root;			
			for(int i = 0; i < s.size(); i++){
				actual = actual -> m[s[i]];
				if(ant >= actual -> p && (actual -> p != 1 || ant != 1)) c++;
				
				ant = actual -> p;
			}
		
			
			sum += c;
		}

		cout<<"Case #"<<casos++<<": "<<sum<<endl;
	}
	
	return 0;
}