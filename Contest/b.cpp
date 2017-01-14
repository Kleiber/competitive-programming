#include<bits/stdc++.h>
using namespace std;
double n, m;
string s;
vector< pair<string, double> > V;
map<string, double> M;

bool orden(pair<string, double> p1, pair<string, double> p2){
	if(p1.second == p2.second) return M[p1.first] > M[p2.first];
	return p1.second > p2.second;
}

double round(double r,int n_digit){
   int n=pow(10,n_digit);
   r=((float)((int)(r*n+0.5)))/n;
   return(r);
}
   
int main(){	
	while(cin>>n>>m){
	
		V.clear();
		M.clear();
		
		int num = 20;
		for(int i = 0; i < n; i++){
			cin>>s;
			V.push_back(make_pair(s,0.0));
			
			M[s] = num;
			num--;
		}
		
		for(int i = 0; i < m; i++){
			cin>>s;
			int ind = -1;
			int cont = 0;
			for(int j = 0; j < s.size(); j++){
				if(s[j] == 'X'){
					cont++;
					ind = j;
				}
			}
			
			if(cont == 1) V[ind].second++;
		}
		
		double ans = 0.0;
		for(int i = 0; i < n; i++){
			V[i].second = (100.00*V[i].second)/m;
			ans += V[i].second;
			V[i].second = round(V[i].second , 2);
			
			//cout<<V[i].second<<endl;
		}
		
		sort(V.begin(), V.end(), orden);
		
		
		
		
		for(int i = 0; i < n; i++){
			cout<<V[i].first;
			printf(" %.2f",V[i].second);
			cout<<"%"<<endl;
		}
		//cout<<ans<<endl;
		printf("Invalid %.2f", 100.00 - ans);
		cout<<"%"<<endl;
	}
	
	
	
	return 0;
}