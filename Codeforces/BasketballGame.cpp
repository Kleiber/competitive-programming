#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
bool orden(pair < string, pair<int,int> >  p1, pair < string, pair<int,int> >  p2){
    if(p1.second.first != p2.second.first) return p1.second.first > p2.second.first;
    else return p1.second.second > p2.second.second;
}

int main(){
	int T;
	cin>>T;
	for(int k = 0; k < T; k++){
		string n;
		int N,M,P,p,h;
		vector< pair< string, pair<int,int> > > V;
		cin>>N>>M>>P;
		
		for(int i = 0; i < N; i++){
			cin>>n>>p>>h;
			V.push_back(make_pair(n, make_pair(p,h)));
		}
		
		sort(V.begin(), V.end(), orden);
		
		int c1 = 0,c2 = 0;
		queue<string> T1, T2, R1, R2;
		stack<string> P1, P2;
		
		for(int i = 0; i < V.size(); i++){
			if(i % 2 == 0){
				if(c1 >= P)R1.push(V[i].first);
				else{
					P1.push(V[i].first);
					c1++;
				}
			}else{
				if(c2 >= P) R2.push(V[i].first);
				else{
					P2.push(V[i].first);
					c2++;
				}
			}
		}
		
		while(!P1.empty()){
			T1.push(P1.top());
			P1.pop();
		}
		while(!P2.empty()){
			T2.push(P2.top());
			P2.pop();
		}
		
		if(R1.size() > 0 || R2.size() > 0){
			for(int i = 0; i < M; i++){
				if(R1.size() > 0){
					T1.push(R1.front());
					R1.push(T1.front());
					T1.pop();
					R1.pop();
				}
				
				if(R2.size() > 0){
					T2.push(R2.front());
					R2.push(T2.front());
					T2.pop();
					R2.pop();
				}
				
			}
		}
		
		vector<string> Ans;
		while(!T1.empty()){
			Ans.push_back(T1.front());
			T1.pop();
		}
		while(!T2.empty()){
			Ans.push_back(T2.front());
			T2.pop();
		}
		
		sort(Ans.begin(), Ans.end());

		cout<<"Case #"<<k+1<<": ";
		for(int i = 1; i <= Ans.size(); i++){
			if(i != Ans.size()) cout<<Ans[i-1]<<" ";
			else cout<<Ans[i-1]<<endl;
		}
	}
	return 0;
}