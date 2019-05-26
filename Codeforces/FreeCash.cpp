#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,m,h,m1,h1,a = 1;
	vector<int> V;
	cin>>n;
	cin>>h>>m;
	n--;
	while(n--){
		cin>>h1>>m1;
		if(m1 == m && h1 == h)
			a++;
		else{
			V.push_back(a);
			a = 1;
		}
		m = m1;
		h = h1;
	}
	V.push_back(a);
	
	sort(V.begin(),V.end());
	cout<<V[V.size() - 1]<<endl;
	return 0;
}