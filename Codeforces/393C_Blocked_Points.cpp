#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n == 0) cout<<1<<endl;
	else cout<<4 * ((long long)(n* sqrt(2)))<<endl;
	return 0;
}
