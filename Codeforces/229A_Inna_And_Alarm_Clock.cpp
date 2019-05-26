#include <iostream>
#include <set>
#include<algorithm>
using namespace std;

int main() {
	int n,x,y;
	cin>>n;
	
	set<int> X, Y;
	
	for(int i = 0; i < n; i++){
		cin>>x>>y;
		X.insert(x);
		Y.insert(y);
	}
	
	cout<<min(X.size(),Y.size());
	return 0;
}