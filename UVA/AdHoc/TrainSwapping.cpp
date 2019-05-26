#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,l,e;
	cin>>n;
	while(n--){
		vector<int> V;
		int cont = 0;
		cin>>l;
		for(int i = 0; i < l; i++) cin>>e,V.push_back(e);
		
		for(int i = 0; i < l; i++){
			for(int j = i + 1; j < l; j++){
				if(V[j] < V[i]){
					int tem = V[i];
					V[i] = V[j];
					V[j] =  tem;
					cont++;
				}
			}
		}
		cout<<"Optimal train swapping takes "<<cont<<" swaps."<<endl;
	}
	return 0;
}