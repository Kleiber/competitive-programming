#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n, con1 = 0, con2 = 0;
	char c1,c2;
	cin>>n;
	
	vector<string> V(n);
	for(int i = 0; i < n; i++) cin>>V[i];
	c1 = V[0][0];
	c2 = V[0][1];
	
	if(c2 == c1) cout<<"NO"<<endl;
	else{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(V[i][j] == c1){
					if(i == j) con1++;
					else{
						if(i + j == n - 1) con1++;
					}
				}
				else{
					if(V[i][j] == c2) con2++;
				}
			}
		}

		int aux1 = 2*n -1;
		int aux2 = n*n;
		if( con1 == aux1 &&  con2 == aux2 - aux1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}