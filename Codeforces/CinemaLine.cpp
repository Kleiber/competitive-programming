#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
	int A[]= {0,0,0};
	int n,e;
	bool t = 1;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>e;
		if(e == 25) A[0]++;
		if(e == 50){
			if(A[0] > 0) A[0]--;
			else{
				t = 0;
				break;
			}
			A[1]++;
		}
		if(e == 100){
			if((A[0] > 0 && A[1] > 0)){
				A[0]--;
				A[1]--;
			}
			else{
				if(A[0] >= 3){
					A[0]-=3;
				}
				else{
					t = 0;
					break;
				}
			}
			A[2]++;
		}
	}
	
	if(t) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}