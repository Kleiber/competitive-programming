#include<bits/stdc++.h>
#define MAX 10005
using namespace std;
int N;
int A[MAX];

int main(){
	while(cin>>N && N){
		for(int i = 1; i <= N; i++) cin>>A[i];
		
		int sum = 0, ans = 0;
		for(int i = 1; i <= N; i++){
			sum += A[i];
			
			ans = max(sum, ans);
			
			if(sum < 0) sum = 0;
		}
		
		if(ans > 0) cout<<"The maximum winning streak is "<<ans<<"."<<endl;
		else cout<<"Losing streak."<<endl;
	}
	return 0;
}