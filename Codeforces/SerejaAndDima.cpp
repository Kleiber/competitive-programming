#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool orden(int a, int b){
	return a > b;
}
int main(){
	int e;
	cin>>e;
	vector<int> V(e);
	
	for(int i = 0; i < e; i++){
		cin>>V[i];
	}
	
	
	int m = 0,n= 0, ind1 = 0, ind2 = V.size() - 1;
	
	for(int i = 0; i < V.size(); i++){
		int ind;
		if(V[ind1] > V[ind2]){
			ind = ind1;
			ind1++;
		}
		else
		{
			ind = ind2;
			ind2--;
		}
		
		if(i % 2 == 0) m += V[ind];
		else n += V[ind];
	}
	
	cout<<m<<" "<<n<<endl;
	return 0;
}