#include<iostream>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(){
	int r = 0;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			int e;
			cin>>e;
			if(e == 1){
				r = abs(2 - i) + abs(2 - j);
				break;
			}
		}
	}
	cout<<r<<endl;
	return 0;
}