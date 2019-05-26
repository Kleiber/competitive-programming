#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	cin>>n;
	if(n[0] != '-') cout<<n<<endl;
	else{
		int x,y;
		if(n.size() == 1) cout<<0<<endl;
		if(n.size() == 2){
			x = n[1] - '0';
			y = n[2] - '0';
			if( x > y) n.erase(n.begin() + 1);
			else n.erase(n.begin() + 2);
		}
		if(n.size() > 2){
			x = n[n.size() - 1] - '0';
			y = n[n.size() - 2] - '0';
			if( x > y) n.erase(n.begin() + n.size() - 1);
			else n.erase(n.begin() + n.size() - 2);
		}
		
		if(n[1] == '0') n.erase(n.begin());
		
		cout<<n<<endl;
	}
	
	return 0;
}