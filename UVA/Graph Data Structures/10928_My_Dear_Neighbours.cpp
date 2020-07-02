#include<iostream>
#include<vector>
using namespace std;

int main(){
	string s;
	int N;
	cin>>N;
	getline(cin,s);
	while(N--){
		int P;
		cin>>P;
		getline(cin,s);

		vector<int> V;
		int mini = 100000000;

		for(int i = 0; i < P; i++){
			getline(cin, s);

			int grade = 1;
			for(int j = 0; j < s.size(); j++){
				if(s[j] == ' ') grade++;
			}

			V.push_back(grade);
			mini = min(mini, grade);
		}

		bool flag = 0;
		for(int i = 0; i < V.size(); i++){
			if(V[i] == mini){
				if(flag) cout<<" ";
				cout<<i+1;	
				flag = 1;
			}
		}cout<<endl;
		getline(cin, s);
	}

	return  0;
}