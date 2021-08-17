#include<iostream>
#include<vector>
#include<sstream>
#include<stack>
using namespace std;

int main(){
	int T;
	string s;

	cin>>T;
	getline(cin, s);
	getline(cin, s);

	int cases = 0;
	while(T--){

		if(cases) cout<<endl;

		vector<int> A, L, M, P;
		int len = 0;
		int it = 0;

		while(getline(cin,s) && s != ""){
			stringstream in(s);
			int num;
			in>>num;

			int ind = A.size();
			A.push_back(num);

			int pos = lower_bound(L.begin(), L.end(), num) - L.begin();
			if(pos == L.size()){
				L.push_back(num);
				M.push_back(ind);
			}else{
				L[pos] = num;
				M[pos] = ind;
			}

			P.push_back(pos? M[pos - 1]: -1);

			if(pos + 1 >= len){
				len = pos + 1;
				it = ind;
			}
		}

		stack<int> S;
   		while(P[it] >= 0){
      		S.push(A[it]);
      		it = P[it];
   		}
   		S.push(A[it]);

   		cout<<"Max hits: "<<len<<endl;
   		while(!S.empty()){
      		cout<<S.top()<<endl;
      		S.pop();
   		}

   		cases++;
	}

	return 0;
}