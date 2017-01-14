#include<bits/stdc++.h>
using namespace std;
int T, casos;

int main(){
	cin>>T;
	casos = 1;
	while(T--){
		string s;
		cin>>s;
		
		string ans1 = s, ans2 = s;
		for(int i = 0; i < s.size(); i++){
			for(int j = 0; j < s.size(); j++){
				string s1 = s;
				
				swap(s1[i], s1[j]);
				
				//cout<<s1<<endl;
				
				if(s1[0] != '0'){
					ans1 = min(ans1, s1);
					ans2 = max(ans2, s1);
				}
			}
		}
		
		cout<<"Case #"<<casos<<": "<<ans1<<" "<<ans2<<endl;
		casos++;
	}
	return 0;
}