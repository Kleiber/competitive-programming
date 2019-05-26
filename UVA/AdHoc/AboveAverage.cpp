#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int N;
	cin>>N;
	for(int i = 0; i < N; i++){
		int n,sum = 0;
		vector<int> V;
		
		cin>>n;
		
		for(int i = 0; i < n; i++) {
			int aux;
			cin>>aux;
			V.push_back(aux);
			sum += aux;
		}
		
		double me = sum/n;
		
		double cont = 0;
		for(int i = 0; i < n; i++)
			if(V[i] > me) cont++;
		
		double ans = 100.0*cont/n;
		
		printf("%.3f%%\n",ans);
	}
	return 0;
}