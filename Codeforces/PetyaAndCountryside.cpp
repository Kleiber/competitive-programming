#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int M[n];
	for(int i = 0; i < n; i++) cin>>M[i];
	
	int a = 0, max = 0;
	for(int i = 1; i < n; i++){
		if(M[i] >= M[i-1]) a++;
		else{
			if(a > max) max = a;
			a = 0;
		}
	}
	
	for(int i = 1; i < n; i++){
		if(M[i] <= M[i-1]) a++;
		else{
			if(a > max) max = a;
			a = 0;
		}
	}
	
	cout<<max<<endl;
	return 0;
}