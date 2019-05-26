#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool orden(pair <int, int> p1, pair <int, int> p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    else return p1.first > p2.first;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector< pair<int,int> > V(n);
	
	for(int i = 0; i < n; i++) 
		cin>>V[i].first>>V[i].second;
	
	sort(V.begin(), V.end(), orden);
	
	int cont = 1;
	k--;
	
	for(int i = k + 1; i < V.size(); i++)
		(V[i].first == V[k].first && V[i].second == V[k].second)? cont++ : i = V.size() + 1;
	for(int i = k - 1; i >= 0; i--)
		(V[i].first == V[k].first && V[i].second == V[k].second)? cont++ : i = -1;
		
	cout<<cont<<endl;
	return 0;
}