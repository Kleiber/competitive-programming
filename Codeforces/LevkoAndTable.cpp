#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int M[n][n];
	memset(M,0,sizeof(M));
	for(int i = 0; i < n; i++) M[i][i] = k;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<M[i][j];
			if(j != n-1) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}