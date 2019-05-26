#include<iostream>
#include<algorithm>
using namespace std;
int main (){
	int i,j;
	while(cin>>i>>j){
		int max = 0,len = 0,a = i,b = j;
		
		if(i > j) swap(i,j);		

		while(i <= j){
			int n = i;
			len = 1;
			while(n != 1){
				if(n & 1)  n = 3*n +1;
				else  n /=2;
				len++;
			}
			
			if(len > max) max = len;
			i++;
		}
		cout<<a<<" "<<b<<" "<<max<<endl;
	}

    return 0;
}