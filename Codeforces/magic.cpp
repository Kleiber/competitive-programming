#include<iostream>
#include<string.h>
using namespace std;
int M[3][3];
int main(){
	int e,s = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin>>e;
			M[i][j] = e;
			s+=e;
		}
	}
	int c = s/2;
	M[0][0] = c - (M[0][1] + M[0][2]);
	M[1][1] = c - (M[1][0] + M[1][2]);
	M[2][2] = c - (M[2][0] + M[2][1]);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}