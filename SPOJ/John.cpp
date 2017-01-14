#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,temp = 0,b = 0;
		cin>>n;
		for(int i = 0; i < n; i++) {
			int  c;
			cin>>c;
			if(c != 1) b = 1;
			temp ^= c;
		}
   
		if(!b) cout<< (n % 2 == 0 ? "John" : "Brother")<<endl;
		else cout<< (temp ? "John" : "Brother")<<endl;
  
	}
	
	return 0;
}