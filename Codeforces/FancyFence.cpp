#include <iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int a;
		cin>>a;
		if(360%(180-a)==0)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}