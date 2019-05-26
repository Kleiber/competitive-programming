#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n,e,ind1,ind2,i=0,p=0,k = 0;
	cin>>n;
	while(n--){
		cin>>e;
		k++;
		if(e % 2 == 0) p++,ind1 = k;
		else i++,ind2 = k;
	}
	
	if(i < p) cout<<ind2<<endl;
	else cout<<ind1<<endl;
	return 0;
}