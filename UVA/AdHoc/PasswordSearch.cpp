#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	string s;
	int n;
	while(cin>>n>>s){
		map<string,int>	M;
		map<string,int>::iterator it;
		for(int i = 0; i < s.length() - n + 1; i++)
			M[s.substr(i,n)]++;
		string res = "";
		int max = 0;
		for(it = M.begin(); it != M.end(); it++){
			if((*it).second > max){
				res=(*it).first;
				max=(*it).second;
			}
		}
		cout<<res<<endl;
	}
}