#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main(){
	vector<int> V(3);
	map<char,int> M;
	
	cin>>V[0]>>V[1]>>V[2];
	
	M[V[0]] = 'a';
	M[V[1]] = 'b';
	M[V[2]] = 'c';
	
	sort(V.begin(),V.end());
	
	int aux = (V[1] + V[0]) - V[2];
	
	if(aux < 0 || (aux%2!=0)) cout<<"Impossible"<<endl;
	else{
		aux = aux / 2;
		if(M[V[2]] == 'a'){
			if(M[V[1]] == 'b')
				cout<<V[1] - aux<<" "<<aux<<" "<<V[0] - aux<<endl;
			else
				cout<<V[0] - aux<<" "<<aux<<" "<<V[1] - aux<<endl;
		}
		if(M[V[2]] == 'b'){
			if(M[V[1]] == 'a')
				cout<<V[1] - aux<<" "<<V[0] - aux<<" "<<aux<<endl;
			else
				cout<<V[0] - aux<<" "<<V[1] - aux<<" "<<aux<<endl;
		}
		if(M[V[2]] == 'c'){
			if(M[V[1]] == 'b')
				cout<<aux<<" "<<V[1] - aux<<" "<<V[0] - aux<<endl;
			else
				cout<<aux<<" "<<V[0] - aux<<" "<<V[1] - aux<<endl;
		}
	}
	
	return 0;
}
