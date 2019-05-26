#include<iostream>
using namespace std;
int main(){
	int n,k; 
	string s;
	cin>>n>>k;
	int sum=0;
	for (int i = 0; i < n; ++i){
		cin>>s;
		int M[10]={0};
		
		for (int j = 0; j < s.size(); ++j) M[s[j]-'0']++;
		
		int cont=0;
		 
		for (int j = 0; j <= k; ++j){
			if(M[j]==0) cont=1;
		}
		
		if(cont==0) sum++;
	}
	
	cout<<sum<<endl;	
	return 0;
}