#include<iostream>
#include<stdio.h>
#include<vector>
// 983318382
#include<algorithm>
using namespace std;

bool orden(pair<int, char> p1, pair<int, char> p2){
	return p1.first < p2.first;
}

int f(int h, int m, int s){
	return h * 3600 + m * 60 + s;
}

int main(){
	int n, h, m, s;
	char c;
	while(cin>>n && n){
	
		int x = 0, e = 0;
		vector< pair<int,char> > V;
		
		for(int i = 0; i < n; i++){
			scanf("%d:%d:%d %c", &h, &m, &s, &c);	
			V.push_back(make_pair(f(h,m,s), c));
			
			if(c == 'E') e++;
			if(c == 'X') x++;
		}
		
		sort(V.begin(), V.end(), orden);
		
		int ans = 0, cont = 0;
		
		for(int i = 0; i < V.size(); i++){
			if(V[i].second == '?'){
				if(e != n/2) {
					e++;
					cont++;
				}
				else {
					x++;
					cont--;
				}
			}
			
			if(V[i].second == 'E') cont++;
			if(V[i].second == 'X') cont--;
			
			ans = max(ans, cont);
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
