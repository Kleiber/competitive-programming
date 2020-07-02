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
bool isconvert(string d){
    if(d[2]  >=  '5')  return 1;
    else return 0;
}
string function(string e){
    if(e[e.size() - 1] != '9' ){
        char c= e[e.size() -1] +'1' - '0';
        return e.substr (0,e.size() -1) + c;
    }
    else return "GOTO Vasilisa.";
}
int main()
{
    string s,ans ="",d ="0";
    bool f = false;
    cin>>s;
    for(int i = 0; i < s.size();i++){
        if(s[i] != '.' && !f) {ans += s[i];} 
        else f = true;
        if(f) d += s[i];
        if(d.size() == 3) break;
    }
    if(isconvert(d) && d.size() > 1) cout<<function(ans);
    else {
        if(ans[ans.size() -1] == '9') cout<<"GOTO Vasilisa.";
        else cout<<ans;
    }
    return 0;
}