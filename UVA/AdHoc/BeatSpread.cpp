#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>  
#include <cstdlib>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>
#define PI 3.1416
using namespace std;  
int main(){
	int casos;
	for(int i = 0; i < casos ; i++){
		int a,b,x,y;
		cin>>a>>b;
		if (a>=b&&(a+b)%2==0){
            x=(a+b)/2;
            y=(a-b)/2;
            cout<<x<<" "<<y<<endl;
        }else
			cout<<"impossible"<<endl;	
	}
	return 0;
}

