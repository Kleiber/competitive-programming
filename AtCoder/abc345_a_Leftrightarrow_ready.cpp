/**
*  Generated by tpp tool
*  File: abc345_a_Leftrightarrow.cpp
*  Created: 16-03-2024 10:51:25
**/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;


int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;

    int len = s.size();
    int cont = 0;

    for(int i = 0; i < len; i++) {
      if(s[i] == '=') cont++;
    }

    if(s[0] == '<' && s[len - 1] == '>' && (len - cont == 2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
