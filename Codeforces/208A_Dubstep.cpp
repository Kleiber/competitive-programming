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
int main(){
  vector<string>V;
  string c,ans="";
  cin>>c;
  int pos = c.find("WUB");
  while(pos != -1 ) {
    if(pos != 0) {
      ans += c.substr (0,pos) +" ";
      c.erase(0,pos); 
    }else{
      c.erase(0, 3);
    }pos = c.find("WUB");
  }
  if(c.size() != 0) ans += c +" ";
  
  cout<<ans.substr(0,ans.size() - 1)<<endl;   
  return 0;
}
