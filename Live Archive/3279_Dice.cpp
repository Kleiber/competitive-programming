#include<iostream>
using namespace std;
int main(){
	string f, s, key;
	while(cin>>f && cin>>s && cin>>key){
		if(f == "#" && s == "#" && key == "#") break;
		
		int n, num, odd = 0, even = 0;
		
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>num;
			if(num % 2) odd++;
			else even++;
		}
		
		if(key == "even") cout<<f<<" "<<odd<<" "<<s<<" "<<even<<endl;
		else cout<<f<<" "<<even<<" "<<s<<" "<<odd<<endl;
	}
	return 0;
}