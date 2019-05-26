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
#include<string.h>
using namespace std;
bool isvocal(char c){
	if(c =='a' || c =='e' || c =='i' || c =='o' || c =='u' || 
	   c =='A' || c =='E' || c =='I' || c =='O' || c =='U' ) 
	   return true;
	else 
		return false;
}
int main(){
    char c,cons;
    while(c=getchar()){
        if(c==EOF) return 0;
        if(isvocal(c)){
            while(isalpha (c)){
                cout<<c;
                c=getchar();
            }
            cout<<"ay";
        }

        else if(isalpha(c)){
            cons=c;
            c=getchar();
            while(isalpha (c)){
                cout<<c;
                c=getchar();
            }
            cout<<cons<<"ay";
        }

        cout<<c;
    }
return 0;
}
