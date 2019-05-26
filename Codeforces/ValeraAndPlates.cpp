#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int n,m,k;
	int ans = 0,e,p = 0,s = 0;
	cin>>n>>m>>k;
	for(int i = 0; i < n; i++){
		cin>>e;
		if(e == 1){
			if(m == 0) ans++;
			else m--;
		}
		else{
			if(k == 0){
				if(m > 0) m--;
				else ans++;
			}
			else k--;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}