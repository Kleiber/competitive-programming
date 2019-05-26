#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n,d,m, sum = 0, sum1 = 0;
	cin>>n>>d;
	vector<int> V(n);
	for(int i = 0; i < n; i++){
		cin>>V[i];
		sum += V[i];
	}
	cin>>m;
	if(n == m) cout<<sum<<endl;
	else{
		if(m > n) cout<<sum - (d*(m-n))<<endl;
		else{
			sort(V.begin(), V.end());
			for(int i = 0; i < m; i++){
				sum1 += V[i];
			}
			cout<<sum1<<endl;
		}
	}
	return 0;
}