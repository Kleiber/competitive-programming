
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct job{
	double id, T, S;
};

bool order(job a, job b){
	if((a.T/a.S) == (b.T/b.S)) return a.id < b.id;
	else return ((a.T/a.S) < (b.T/b.S));
}

int main(){
	int cases;
	cin>>cases;

	int cont = 0;
	while(cases--){

		if(cont != 0) cout<<endl;

		int n;
		cin>>n;

		vector<job> V;
		for(int i = 1; i <= n; i++){
			double t, s;
			cin>>t>>s;
			V.push_back((job){(double)i,t,s});
		}

		sort(V.begin(), V.end(), order);

		cout<<V[0].id;
		for(int i = 1; i < V.size(); i++) cout<<" "<<V[i].id;
		cout<<endl;

		cont++;
	}
	return 0;
}