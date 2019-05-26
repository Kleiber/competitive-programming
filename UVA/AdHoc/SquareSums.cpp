#include<iostream>
#include<cstring>
#include<vector>
#define MAX 10
using namespace std; 
int n;
int M[MAX][MAX];
vector<int> V;
void Sum(){
	int fil,col,aux,sum = 0;
	
	if(n & 1) aux = n/2 + 1;
	else aux = n/2;
	
	for(int k = 0;k < aux; k++){
		col = k;
		for(fil = k; fil <= n - 1 - k; fil++) sum += M[fil][col];
		fil = n - 1 - k;
		for(col = k + 1; col <= n - 1 - k; col++) sum += M[fil][col];
		col = n - 1 - k;
		for(fil = n - 2 - k; fil >= k; fil--) sum += M[fil][col];
		fil = k;
		for(col = n - 2 - k; col >= k + 1; col--) sum += M[fil][col];
		
		V.push_back(sum);
		sum = 0;
	}
}
 
int main(){
	int cases = 0;
	while(cin>>n && n){
	 
		cases++;
		memset(M,0,sizeof(M));
		V.clear();
		 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin>>M[i][j];
		}
		
		Sum();
		
		cout<<"Case "<<cases<<": ";
		cout<<V[0];
		for(int i = 1; i < V.size(); i++) cout<<" "<<V[i];
		cout<<endl;
	}
}
