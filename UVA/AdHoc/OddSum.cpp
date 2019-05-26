#include<iostream>
using namespace std;
int main(){
	int C,cases = 0;
	cin>>C;
	while(C--){
		cases++;
		int a,b,sum = 0;
		cin>>a>>b;
		
		if(!(a & 1)) a++;
		
		for(int i = a; i <= b; i+=2) sum += i;
		
		cout<<"Case "<<cases<<": "<<sum<<endl;
	}
	
	return 0;
}