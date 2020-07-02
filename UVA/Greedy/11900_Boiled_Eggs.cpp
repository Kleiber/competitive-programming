#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool order(int a, int b){
	return a < b;
}

int main(){
	int cases = 1;
	int T;
	cin>>T;
	while(T--){
		int n, P, Q;
		cin>>n>>P>>Q;

		vector<int> V(n);
		for(int i = 0; i < n; i++) cin>>V[i];

		sort(V.begin(), V.end(), order);

		int cant = 0;
		int peso = 0;
		for(int i = 0; i < n; i++){
			if(peso + V[i] <=Q && cant < P){
				peso += V[i];
				cant++;
			}
			else break;
		}

		cout<<"Case "<<cases<<": "<<cant<<endl;
		cases++;
	}

	return 0;
}