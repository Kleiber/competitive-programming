#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<string> V;
int main(){
	int n,ans;
	bool f = 1;
	char c;
	cin>>n;
	
	if(n % 2 == 0) ans = n*n/2;
	else ans =  n*n/2 + 1;
	
	cout<<ans<<endl;
	
	for(int i = 0; i < n; i++){
		if(i % 2 == 0) f = 1;
		else f = 0;
		for(int j = 0; j < n; j++){
			if(f){
				c = 'C';
				f = 0;
			}
			else{
				c = '.';
				f = 1;
			}
			
			cout<<c;
		}
		cout<<endl;
	}
	
	return 0;
}