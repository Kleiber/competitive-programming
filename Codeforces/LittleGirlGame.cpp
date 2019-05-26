#include<iostream>
#include<map>
using namespace std;
int main(){
	string s;
	map<char,int> M;
	map<char,int> :: iterator it;
	
	cin>>s;
	for(int i = 0; i < s.size(); i++) M[s[i]]++;
	
	int c = 0,p = 0,i = 0;
	for(it = M.begin(); it != M.end(); it++){
		int aux = it -> second;
		if(aux % 2 != 0) c++;
		else p++;
		i++;
	}
	//cout<<p<<" "<<c<<" "<<i<<endl;
	
	if(p == i) cout<<"First"<<endl;
	else{
		if(p ==  i - 1) cout<<"First"<<endl;
		else {
			if((c - 1) % 2 == 0) cout<<"First"<<endl;
			else cout<<"Second"<<endl;
		}
	}
	return 0;
}