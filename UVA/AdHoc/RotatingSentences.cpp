#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	string s;
	vector<string> V;
	vector<int> T;
	while(getline(cin,s)){
		V.push_back(s);
		T.push_back(s.size());
	}
	sort(T.begin(),T.end());
	int L = T[T.size() - 1];
	
	for(int i = 0; i < L; i++){
		for(int j = V.size() - 1 ; j >= 0; j--){
			if(i > V[j].size()) cout<<' ';
			else cout<< V[j][i];
		}
		cout<<endl;
	}
	
	return 0;
}