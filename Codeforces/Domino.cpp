#include <iostream>
#include <vector>
using namespace std;
int main(){
	int S[2] = {0,0};
	vector<int> L;
	vector<int> R;
	int n,a,b;
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>a>>b;
		L.push_back(a);
		R.push_back(b);
		S[0] += a;
		S[1] += b;
	}
	bool f = 0;
	//cout<<S[0]<<" "<<S[1]<<endl;
	if(S[0] % 2 == 0 && S[1] % 2 == 0) cout<<0<<endl;
	else{
		if(S[0] % 2  != 0 && S[1] % 2 != 0){
			for(int i = 0; i < n; i++){
				if((L[i] % 2 != 0 && R[i] % 2 == 0)||(R[i] %2 != 0 && L[i] % 2 == 0)){
					f = 1;
					break;
				}
			}
		}
		
		if(f) cout<<1<<endl;
		else cout<<-1<<endl;
		
	}
	return 0;
}