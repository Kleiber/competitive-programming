#include<iostream>
using namespace std;
int main(){
	int T, N;
	cin>>T;
	while(T--){
		cin>>N;
		if(N % 3 == 0) cout<<N<<" is a multiple of 3"<<endl;
		else cout<<N<<" is not a multiple of 3"<<endl;
	}
	return 0;
}