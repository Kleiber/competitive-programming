#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
bool orden(pair<int,int> a,pair<int,int> b)
{
    if(a.second < b.second) return true;
    if(a.second == b.second){
        if(a.first > b.first) return true;
    }
    return false;
}
int main(){
	string s;
	int espacio = 1;
	while(getline(cin,s)){
		map<char,int> M;
		for(int i = 0; i < s.size(); i++) M[s[i]]++;
		
		vector< pair<char,int> > V(M.begin(), M.end());
		sort(V.begin(),V.end(),orden);
		if(espacio++ != 1) cout<<endl;
		for(int i = 0; i < V.size(); i++) cout<<(int)V[i].first<<" "<<V[i].second<<endl;
	}
	return 0;
}