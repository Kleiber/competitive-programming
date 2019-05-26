#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n, ans = 0;
	cin>>n;
	vector<int> V(n);
	
	for(int i = 0; i < n; i++) cin>>V[i];
	
	sort(V.begin(), V.end());
	
	int temp = V[0];
	if(V[0] > n) cout<<n<<endl;
	else{
		for(int i = 1; i < V.size(); i++){
			if(V[i] > n || V[i] == temp) ans++;
			else{
				if(V[i] != temp) temp = V[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}