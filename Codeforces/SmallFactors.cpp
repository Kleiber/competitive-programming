#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
vector<long long> D(35),T(35);
void init(){
	D[0] = 1, D[1] = 2;
	T[0] = 1, T[1] = 3;
	for(int i = 2; i < 31; i++) D[i] = 2*D[i-1];
	for(int i = 2; i < 31; i++) T[i] = 3*T[i-1];
}
int main(){
	init();
	long long n;
	while (cin>>n  && n){
		long long min = 2147483647;
		
		for ( int i = 0; i < 31; i++){
			for ( int j = 0; j < 31; j++){
				long long num = D[i] * T[j];
				if (num >= n && num < min){
					min = num;
					break;
				}
			}
		}
		cout<<min<<endl;
	}
	return 0;
}