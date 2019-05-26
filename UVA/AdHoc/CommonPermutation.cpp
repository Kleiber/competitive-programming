#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	string s1,s2;
	while(getline(cin,s1)){
		getline(cin,s2);
		map<char,int> M;
		vector<char> V;
		for(int i = 0; i < s1.size(); i++) M[s1[i]]++;
		for(int i = 0; i < s2.size(); i++){
			if(M[s2[i]]){
				V.push_back(s2[i]);
				M[s2[i]]--;
			}
		}
		sort(V.begin(),V.end());
		for(int i = 0; i < V.size(); i++) cout<<V[i];
		cout<<endl;
	}
	return 0;
}