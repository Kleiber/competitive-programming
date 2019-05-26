#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
bool orden(pair <char, int> p1, pair <char, int> p2){
    if(p1.second != p2.second) return p1.second > p2.second;
    else return p1.first < p2.first;
}

int main(){
	int n;
	string s;
	cin>>n;
	getline(cin,s);
	while(n--){
		map<char,int> M;
		getline(cin,s);
		for(int i = 0; i < s.size(); i++){
			s[i] = tolower(s[i]);
			if(s[i] >= 'a' && s[i] <= 'z') M[s[i]]++;
		}
		
		vector< pair<char,int> > V(M.begin(),M.end());
		sort(V.begin(),V.end(),orden);
		int max = V[0].second;
		for(int i = 0; i < V.size(); i++){
			if(V[i].second == max) cout<<V[i].first;
			if(V[i].second < max) break;
		}
		cout<<endl;
	}
	return 0;
}