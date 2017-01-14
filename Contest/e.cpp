#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	string s;
	
	while(cin>>n>>s){
		long long dos = 0, uno = 0, sum = 0, ans = 0;
		
		for(int i = 0; i < s.size(); i++){
			int d = s[i] - '0';
			
			if(sum + d > n){
				if(d == 1){
					if(dos > 0 ){
						sum -= 2;
						sum += 1;
						uno++;
						dos--;
					}
				}
			}else{
				if(d == 1){
					uno++;
					sum += 1;
				}
				else{
					dos++;
					sum += 2;
				}
			}
			
			
			ans += (uno + dos);
		}
		
		cout<<ans<<endl;
	}
	return 0;
}