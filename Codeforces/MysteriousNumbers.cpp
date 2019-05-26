#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	reverse(s2.begin(),s2.end());
	long a = atoi(s1.c_str());
	long b = atoi(s2.c_str());
	long ans = a+ b;
	cout<<ans<<endl;
	return 0;
}