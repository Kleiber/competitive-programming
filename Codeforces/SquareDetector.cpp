#include<iostream>
#include<vector>
using namespace std;
int main(){
	int T;
	cin>>T;
	for(int k = 0; k < T; k++){
		int N;
		cin>>N;
		vector<string> V(N);
		vector<pair<int,int> > P;
		
		for(int i = 0; i < N; i++) cin>>V[i];
		
		for(int i = 0; i < V.size(); i++){
			for(int j = 0; j < V[i].size(); j++){
				if(V[i][j] 	== '#') P.push_back(make_pair(i,j));
			}
		}
		
		if(P.size() == 0) cout<<"Case #"<<(k+1)<<": NO"<<endl;
		else{
			int ini = P[0].second, max = P[0].second,cont = 1, rango = ini = P[0].second;
			bool f = 1, ans = 1;
			
			for(int i = 1; i < P.size(); i++){
				if(P[i].first != P[i - 1].first){
					if(f) rango = max;
					else{
						if(rango != max){
							ans = 0;
							break;
						}
					}
					
					if(cont > 1) f = 0;
					
					if(ini != P[i].second){
						ans = 0;
						break;
					}
					
					max = P[i].second;
					cont++;
				}
				else{
					if(max + 1 == P[i].second) max = P[i].second;
					else{
						ans = 0;
						break;
					}
				}
			}
			
			int t = rango - ini + 1;
			if(ans &&  t == cont && max == rango) cout<<"Case #"<<(k+1)<<": YES"<<endl;
			else cout<<"Case #"<<(k+1)<<": NO"<<endl;
		}
		
	}
	return 0;
}