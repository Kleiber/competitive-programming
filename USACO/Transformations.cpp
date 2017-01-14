/*
ID: edison11
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define MAX 11
using namespace std;
struct Matrix{
	char mat[MAX][MAX];
};

int N;

bool cmp(Matrix A, Matrix B){
	bool f = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(A.mat[i][j] != B.mat[i][j]){
				f = 0;
				break;
			}
		}
	}
	return f == 1;
}

Matrix rot(Matrix A){
	Matrix ans;	
	int ind  = N - 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ans.mat[j][ind] = A.mat[i][j];
		}
		ind--;
	}
	return ans;
}

Matrix ref(Matrix A){
	Matrix ans;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ans.mat[i][j] = A.mat[i][N - j - 1];
		}
	}
	return ans;
}


int main (){
	ofstream cout ("transform.out");
    ifstream cin ("transform.in");
	
	string s;
	Matrix A,B,R;
	cin>>N;
	
	for(int i = 0; i < N; i++){
		cin>>s;
		for(int j = 0; j < N; j++){
			A.mat[i][j] = s[j];
		}
	}
	for(int i = 0; i < N; i++){
		cin>>s;
		for(int j = 0; j < N; j++){
			B.mat[i][j] = s[j];
		}
	}
	
	R = rot(A);
	if(cmp(R,B)) cout<<1<<endl;
	else{
		R = rot(R);
		if(cmp(R,B)) cout<<2<<endl;
		else{
			R = rot(R);
			if(cmp(R,B)) cout<<3<<endl;
			else{
				R = rot(R);
				R = ref(R);
				if(cmp(R,B)) cout<<4<<endl;
				else{
					bool f = 1;
					for(int i = 0; i < 3; i++){
						R = rot(R);
						if(cmp(R,B)){
							cout<<5<<endl;
							f = 0;
							break;
						}
					}
					
					if(f){
						if(cmp(A,B)) cout<<6<<endl;
						else cout<<7<<endl;
					}
					
				}
				
			}
		}
	}
	return 0;
}