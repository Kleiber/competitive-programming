#include<iostream>
#include<math.h>
#define MAX 3000
using namespace std;
int main(){
	int M[MAX];
	int n,d,ans = 0;
	cin>>n>>d;
	for(int i = 0; i < n; i++){
		cin>>M[i];
		if(i != 0){
			if(M[i - 1] >= M[i]){
				int aux = ceil((double)(M[i - 1] - M[i] + 1)/(double)d);
				//cout<<"aux = "<<aux<<endl;
				M[i] += aux * d;
				ans += aux;
				
				//cout<<"M[i] = "<<M[i]<<endl;
				//cout<<"ans = "<<ans<<endl;
			}
		}
		
		//cout<<M[i]<<" ";
	}
	//cout<<endl;
	cout<<ans<<endl;
	return 0;
}