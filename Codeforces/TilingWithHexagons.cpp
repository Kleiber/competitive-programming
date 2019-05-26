#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	long ans = b*c + (a-1)*(b-1) + (a-1)*c;
	cout<<ans<<endl;
	return 0;
}