#include<iostream>
#define MAX 200005
using namespace std;
int main(){
	string s,ans = "";
	int  M[MAX];
	cin>>s;
	
	M[0] = 0;
	int cont = 1,ind = 1;
	char u = s[0];
	
	for(int i = 1; i < s.size(); i++){
		if(s[i] != u || cont == 3){
			if(cont == 3){
				
				M[ind] = 1;
				ans+=s[i-1];
			}
			else{
				if(cont == 2){
					if(M[ind - 1] == 2){
						M[ind] = 1;
						ans += u;
					}else{
						ans += u;
						M[ind] = 2;
						ans += u;
					}
				}else{
					ans += u;
				}
			}
			u = s[i];
			cont = 1;
			ind++;
		}else cont++;
		
	}
	
	if(cont == 3) ans += u;
	else{
		if(cont == 1) ans += u;
		else{
			if(cont == 2 && M[ind - 1] == 2){
				ans += u;
			}else{
				ans += u;
				ans += u;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}