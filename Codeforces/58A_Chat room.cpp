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

using namespace std;
int main()
{
        string s;
		int cont=0;
		cin>>s;
         for(int i=0;i<s.size();i++)
         {
            if(s.at(i)=='h' && cont==0) 
				cont++;
            if(s.at(i)=='e' && cont==1) 
				cont++;
            if(s.at(i)=='l' && (cont==2 || cont==3)) 
				cont++;
            if(s.at(i)=='o' && cont==4) 
				cont++;
         }
		
        if(cont==5) 
			cout<<"YES"<<endl;
        else 
			cout<<"NO"<<endl;

    return 0;
}