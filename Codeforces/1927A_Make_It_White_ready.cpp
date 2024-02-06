/**
*  Generated by tpp tool
*  File: 1927A_Make_It_White.cpp
*  Created: 06-02-2024 15:48:49
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


#define BLACK 'B'

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases;
    cin>>cases;

    while(cases--) {
      int n;
      string s;
      cin>>n>>s;

      int l = -1;
      int r = -1;
      for(int i = 0; i < n; i++) {
        if(s[i] == BLACK && l == -1) l = i;
        if(s[n - 1 - i] == BLACK && r == -1) r = n - 1 - i;
      }

      int ans = r - l + 1;
      cout<<ans<<endl;
    }

    return 0;
}

