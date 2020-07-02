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
using namespace std;
int main()
{
  string cadena ;
  cin>>cadena;
  if(cadena.find("0000000") != -1  || cadena.find("1111111") !=-1)
    cout<<"YES";
  else
    cout<<"NO";
    return 0;
}