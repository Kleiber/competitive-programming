#include<iostream>
using namespace std;
int main(){
	int n,a,b,c,d, r1,r2, j = -1;
	cin>>n;
	
	for(int i = 1; i <= 4; i++){
		cin>>a>>b>>c>>d;
		if(a + c <= n) {j = i; r1 = a; r2 = c; break;}
		if(a + d <= n) {j = i; r1 = a, r2 = d; break;}
		if(b + c <= n) {j = i; r1 = b, r2 = c; break;}
		if(b + d <= n) {j = i; r1 = b, r2 = d; break;}
	}
	
	if(j == -1) cout<<-1<<endl;
	else cout<<j<<" "<<r1<<" "<<r2 + (n - r1 - r2)<<endl;
	
	return 0;	
}