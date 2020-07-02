#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct query{
	long long id;
	long long period;
	long long acum;
};

struct order{
	bool operator()(const query& a, const query& b){
		if(a.acum == b.acum) return a.id > b.id;
		else return a.acum > b.acum;
	}
};

int main(){
	priority_queue<query, vector<query>, order> Q;

	string cad;
	long long id, period;
	while(cin>>cad && cad != "#"){
		cin>>id>>period;
		Q.push((query){id, period, period});
	}

	long long n;
	cin>>n;

	long long cont = 0;
	while(cont != n){
		query q = Q.top();
		Q.pop();
		cout<<q.id<<endl;
		q.acum += q.period;
		Q.push(q);
		cont++;
	}
	
	return 0;
}