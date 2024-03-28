/**
*  Generated by tpp tool
*  File: abc344_a_Spoiler.cpp
*  Created: 09-03-2024 09:00:55
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

    string ans = "";
    bool found = 0;

    for(int i = 0; i < s.size(); i++) {
      if(s[i] == '|') {
        found = !found;
        continue;
      }

      if(!found) ans += s[i];
    }

    cout<<ans<<endl;

    return 0;
}
