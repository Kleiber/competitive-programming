#include<bits/stdc++.h>
using namespace std;
int N, M;
int main(){
	while(cin>>N>>M){
		int t = N*M, cont = 0;
		map<int, int> M1;
		
		for(int i = M; i < t; i += M){
			M1[i]++;
			cont++;
		}
		
		for(int i = N; i < t; i += N) M1[i]++;
	
		//vector< pair<int,int> > V(M1.begin(), M1.end());
		
		//for(int i = 0; i < V.size(); i++){
			//cout<<V[i].first<<endl;
		//}
		
		cout<<M1.size() - cont<<endl;
	}
}