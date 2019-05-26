#include<iostream>
using namespace std;
int main(){
	string s1,s2;
	while(cin>>s1>>s2){
		int n,c = 0,in = 0;
		for(int i = 0; i < s1.size(); i++){
			int n = s2.find(s1[i]);
			s2[n] = '*';
			while(n < in && n != -1){
				n = s2.find(s1[i]);
				s2[n] = '*';
			}
			//cout<<s2<<endl;
			if(in == -1 || n < in) break;
			else c++;
			in = n;
		}
		if(c == s1.size()) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}