#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int> V(4), A;
int main(){
	string s;
	cin>>s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'n') V[0]++;
		if(s[i] == 'i') V[1]++;
		if(s[i] == 'e') V[2]++;
		if(s[i] == 't') V[3]++;
	}
	
	for(int i = 0; i < V.size(); i++){
		if(i == 1 || i == 3) A.push_back(V[i]);
		else{
			if(i == 2) A.push_back(V[i]/3);
			else A.push_back((V[i] - 1)/2);
		}
	}
	
	sort(A.begin(), A.end());
	
	cout<<A[0]<<endl;
	return 0;
}
