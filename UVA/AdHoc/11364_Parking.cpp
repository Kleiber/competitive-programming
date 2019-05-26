#include<bits/stdc++.h>
using namespace std;
bool orden(int a, int b){
	return a < b;
}

int main(){
	int casos;
	cin>>casos;
	
	while(casos--){
		int n, num, ans;
		vector<int> V;
		
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>num;
			V.push_back(num);
		}
		
		sort(V.begin(), V.end(), orden);
		
		ans = 0;
		for(int i = 1; i < n; i++) ans += V[i] - V[i- 1];
		
		cout<<2*ans<<endl;
	}
	
	return 0;
}