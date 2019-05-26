#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n;
	cin>>s;
	
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'L'){
			if(i - 1 >= 0 && s[i - 1] != '*'){
				for(int j = i - 1; j >= 0 ; j--){
					if(s[j] == 'R'){
						int aux = i - j + 1;
						if(aux % 2 != 0) s[j +aux/2] = '.';
						break;
					}else{
						if(s[j] == '.') s[j] = '*';
					}
				}
			}
		}
		
		if(s[i] == 'R'){
			if(i + 1 < s.size() && s[i + 1] != '*'){
				for(int j = i; j < s.size(); j++){
					if(s[j] == 'L'){
						int aux = j - i + 1;
						if(aux % 2 != 0) s[i + aux/2] = '.';
						break;
					}else{
						if(s[j] == '.') s[j] = '*';
					}
				}
			}
		}
	}
	
	
	
	
	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '.') ans++;
	}
	
	cout<<ans<<endl;
	return 0;
}