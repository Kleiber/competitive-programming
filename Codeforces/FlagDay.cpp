#include<iostream>
#include<cstring>
#define MAX 100005
using namespace std;
int main(){
	int A[MAX],n,m;
	cin>>n>>m;
	
	memset(A,0,sizeof(A));
	
	for(int i = 0; i < m; i++){
		int a,b,c;
		bool f[3] ={0};
		cin>>a>>b>>c;
		if(a == 0 && b == 0 && c == 0){
			A[a] = 1;
			A[b] = 2;
			A[c] = 3;
		}else{
			if(A[a] == 1 || A[b] == 1 || A[c] == 1) f[0] = 1;
			if(A[a] == 2 || A[b] == 2 || A[c] == 2) f[1] = 1;
			if(A[a] == 3 || A[b] == 3 || A[c] == 3) f[2] = 1;
			
			if(!f[0] || !f[1] || !f[2]){
				if(A[a] == 0){
					if(!f[0]) A[a] = 1, f[0] = 1;
					else{
						if(!f[1]) A[a] = 2, f[1] = 1;
						else A[a] = 3, f[2] = 1;
					}
					
				}
				if(A[b] == 0){
					if(!f[0]) A[b] = 1, f[0] = 1;
					else{
						if(!f[1]) A[b] = 2, f[1] = 1;
						else A[b] = 3, f[2] = 1;
					}
				}
				if(A[c] == 0){
					if(!f[0]) A[c] = 1, f[0] = 1;
					else{
						if(!f[1]) A[c] = 2, f[1] = 1;
						else A[c] = 3, f[2] = 1;
					}
				}
			}
		}
	}
		
	for(int i = 1; i <= n; i++){
		if(i != n) cout<<A[i]<<" ";
		else cout<<A[i]<<endl;
	}
	return 0;
}