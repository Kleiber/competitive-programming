#include<iostream>
#include<algorithm>
#include<vector>
#include <stdio.h>
#include <set>
using namespace std;
#define FOR(i,n) for(i = 0; i < n; i++)
#define MAX 20000
multiset<int> H;
int D[MAX], n,m;
bool pagar(){
  int costo = 0,i = 0;
  /*
  FOR(i,n) cout<<D[i]<<" ";
  cout<<endl;
  for (std::multiset<int>::iterator it=H.begin(); it!=H.end(); ++it)
	cout<<*it<<" ";
  cout<<endl;
  */
  for(int i = 0; i < n; i++){
    multiset<int>::iterator j = H.lower_bound(D[i]);
    if (j == H.end()) return false;
    costo += *j;
    H.erase(j);
  }
  if(costo > 0)
	cout<<costo<<endl;
  return true;
}
 
int main(){

	while(cin>>n>>m){
		int e;
		H.clear();
		for(int i = 0; i < n; i++) cin>>D[i];
		for(int i = 0; i < m; i++) cin>>e, H.insert(e);
		if (!pagar()) cout<<"Loowater is doomed!"<<endl;
	}
	return 0;
}