#include<iostream>
using namespace std;
int N;
int f(int n){
	int r = 0;
	while(n/10 != 0){
		r += (n%10)*(n%10);
		n = n /10;
	}
	r += (n * n);
	return r;
}

int fn(int n){
	int e  = N;
	for(int i = 0; i < n; i++) e = f(e);
	return e;
}

pair<int,int> BuscarCicloFloyd(int x){
	int l = f(x),r = f(f(x));
	while(l != r){
		l = f(l);
		r = f(f(r));
	}
	
	int mu = 0;
	r = x;
	while(l != r){
		l = f(l);
		r = f(r);
		mu++;
	}
	
	int lambda = 1;
	l = fn(mu);
	r = f(l);
	while(l != r){
		r = f(r);
		lambda++;
	}
	pair<int,int> P =make_pair(mu,lambda);
	return P;
}

int main(){
	int i = 1,C;
	cin>>C;
	while(C--){
		cin>>N;
		pair<int,int> P = BuscarCicloFloyd(N);
		if(P.second == 1)
			cout<<"Case #"<<i<<": "<<N<<" is a Happy number."<<endl;
		else
			cout<<"Case #"<<i<<": "<<N<<" is an Unhappy number."<<endl;
		i++;
	}
	return 0;
}