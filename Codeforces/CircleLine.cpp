#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,s,t,a = 0, b = 0;
	cin>>n;
	vector<int> V(n);
	for(int i = 0; i < n; i++) {
		cin>>V[i];
		//cout<<V[i]<<" ";
	}
	//cout<<endl;
	cin>>s>>t;
	//cout<<s<<" "<<t<<endl;
	if(s == t) cout<<0<<endl;
	else{
		for(int i = s - 1; i != t - 1 ; i++){
			i = i % V.size();
			if(i == t - 1) break;
			a += V[i];
		}
		for(int j = t - 1; j != s - 1 ; j++){
			j = j % V.size();
			if(j == s - 1) break;
			b += V[j];
		}
		//cout<<a<<" "<<b<<endl;
		if(a < b) cout<<a<<endl;
		else cout<<b<<endl;
	}
	return 0;
}