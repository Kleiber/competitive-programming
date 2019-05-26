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
 long i,j,k;
 char s[11],ss[11],line[25];
 map<string,string>m;

 while( gets(line) ){
  if( strcmp(line,"") ){
   sscanf(line,"%s %s",&s,&ss);
   if( m[ss] == "" )
    m[ss] = s;
  }
  else{
   while( gets(line) ){
    if( m[line] != "" )
     cout << m[line] << '\n';
    else
     cout << "eh\n";
   }
  }
 }


 return 0;
}