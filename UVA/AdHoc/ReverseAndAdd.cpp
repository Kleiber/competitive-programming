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
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;
int main(){
    int casos;
    long long int n,c,sum,r,d;
    cin>>casos;
    while (casos--){
        cin>>n;
        d=n;
        c=0;
        while (1){
            sum=0;
            while (d>0){
                r=d%10;
                sum=sum*10+r;
                d=d/10;
            }
			
            if (n==sum) 
				break;
            else{
                d=sum+n;
                n=sum+n;
                c++;
            }
        }
		cout<<c<<" "<<n<<endl;
    }
    return 0;
}

