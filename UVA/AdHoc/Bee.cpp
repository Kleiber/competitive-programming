#include<iostream>  
#include<vector>
#include<math.h>
#define MAX 100
using namespace std;
long long M[MAX];
long long T[MAX];
void generar(){
	M[0] = 0;T[0] = 1;
	M[1] = 1;T[1] = 2;
	for(int i = 2; i < MAX; i++){
		M[i] = M[i-1] + (T[i-1] - M[i-1]);
		T[i] = M[i-1]*2 + (T[i-1] - M[i-1]) + 1;
	}
}

int main(){
/*
	int N;
	generar();
	//long long A = pow(2,32);
	//cout<<A<<endl;
	while(cin>>N && N != -1){
		cout<<M[N]<<" "<<T[N]<<endl;
	}
*/
	unsigned int a, cociente, resto;
	a = 757;
	cociente = a >> 3;
	resto =  (~((~0) << 3)) & a;
	
	cout<<a<<" "<<cociente<<" "<<resto<<endl;
	
	return 0;
}