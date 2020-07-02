#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
#define MAX 105

int padre[MAX];
int P[MAX][MAX];

void init(int n){
	for(int i = 0; i < n; i++) padre[i] = i;
}

int find(int x){
	if(x == padre[x]) return x;
	else return padre[x] = find(padre[x]);
}

void join(int x, int y){
	int X = find(x);
	int Y = find(y);
	padre[X] = Y;
}

bool listen(int x, int y){
	int ans = 1;
	for(int i = 0; i < MAX; i++){
		if(P[x][i] != P[y][i]){
			ans = 0;
			break;
		}
	}
	return ans;
}


int main(){
	string s;
	int N;
	cin>>N;
	getline(cin, s);
	getline(cin, s);

	for(int cases = 0; cases < N; cases++){
		if(cases != 0) cout<<endl;
		memset(P, 0, sizeof(P));

		int t, p;
		cin>>p>>t;
		getline(cin,s);

		while(getline(cin,s) && s.size() != 0){
			stringstream in(s);
			int pp, tt;
			in>>pp>>tt;
			P[pp][tt] = 1;
		}

		init(p);

		for(int i = 1; i <= p; i++){
			for(int j = i + 1; j <= p; j++){
				if(listen(i, j)) join(i, j);
			}
		}

		int ans = 0;
		for(int i = 0; i < p; i++){
			if(padre[i] == i) ans++;
		}

		cout<<ans<<endl;
	}
	return 0;
}