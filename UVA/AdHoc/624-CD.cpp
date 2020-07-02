#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 100
using namespace std;
int main(){
	int T[MAX];
	int n, p;
	while(cin>>n>>p){
		for(int i = 0; i < p; i++) cin>>T[i];
		
		int ans = 0, lis = 0, sum = 0;
		int mas = 1 << p;
		
		for(int i = 0; i < mas; i++){
			sum = 0;
			
			for(int j = 0; j < p; j++){
				if((1 << j) & i) sum += T[j];
			}
			
			if(sum >= ans && sum <= n){
				ans = sum;
				lis = i;
			}
		}
		
		for(int i = 0; i < p; i++){
			if((1 << i) & lis) cout<<T[i]<<" ";
		}
		
		cout<<"sum:"<<ans<<endl;
	}
	
	return 0;
}