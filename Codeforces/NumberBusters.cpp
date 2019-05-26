#include<iostream>
using namespace std;
int main(){
	long long a,b,w,x,c;
	cin>>a>>b>>w>>x>>c;
	long long ans = 0;
	long long a1 = a, c1 = b;
	
	for(int i = 0; i < 30; i++){
	//while(true){
		cout<<a<<" "<<b<<" "<<w<<" "<<x<<" "<<c<<endl;
		
		if(b >= x) b = b - x;
		if(b < x){
			a = a - 1;
			b = w  - (x - b);
		}
		c = c - 1;
		
		
		if(c <= a){
			cout<<ans<<endl;
			break;
		}
		ans++;
		
		if(c == 0) c = c1;
		if(a == 0) a = a1;
	}
	return 0;
}