#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 100100
using namespace std;
int n, d = 2;
bool P[MAX];
int  A[MAX];
vector< pair<int,int> > R;

void criba(){
	
	for(int i = 0; i < MAX; i++) P[i] = 1;
	
	P[0] = 0;
	P[1] = 0;
	
	for(int i = 2; i < MAX; i++){
		if(P[i]){
			for(int j = 2*i; j < MAX; j+=i)
				P[j] = 0;
		}
	}
}

void solve(int a, int b){
	if (a == b) return;
	if (a > b) swap(a, b);
	
	for(int i = b; i > a; i--)
		if (P[i - a + 1]){
			swap(A[a], A[i]);
			R.push_back(make_pair(a, i));
			solve(i, b);
			break;
		}
}

int main(){
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>A[i];
	
	criba();
	
	
	for (int i = 1; i <= n; i++){
		while (A[i] != i) solve(i, A[i]);
	}
			
	cout<<R.size()<<endl;
	for(int i = 0; i < R.size(); i++){
		cout<<R[i].first<<" "<<R[i].second<<endl;
	}
	return 0;
}

