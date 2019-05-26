#include<bits/stdc++.h>
#define MAX 20005
using namespace std;
int r, s, cont;
int A[MAX];

int main(){
	cin>>r;
	cont  = 1;
	while(r--){
		cin>>s;
		for(int i = 1; i < s; i++) cin>>A[i];
		
		int sum = 0, max = 0, l = 0, r = 0, ind = 0;
		for(int i = 1; i < s; i++){
			sum += A[i];
			
			if(sum > max || (sum == max && i - ind > r - l)){
				max = sum;
				r = i;
				l = ind;
			}
			
			if(sum < 0){
				sum = 0;
				ind = i;
			}
		}
		
		if(max > 0) cout<<"The nicest part of route "<<cont<<" is between stops "<<l + 1<<" and "<<r + 1<<endl;
		else cout<<"Route "<<cont<<" has no nice parts"<<endl;
		
		cont++;
	}
	return 0;
}