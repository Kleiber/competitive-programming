/**
*  Generated by tpp tool
*  File: 1954B_Make_It_Ugly.cpp
*  Created: 14-04-2024 17:46:17
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


const int MAX = 300005;

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--) {
      int n;
      cin>>n;

      vector<int> V(n);
      for(int i = 0; i < n; i++) cin>>V[i];

      int last = -1;
      int ans = MAX;

      for(int i = 0; i < n; i++) {
        if(V[i] != V[0]) {
          ans = min(ans, i - last - 1);
          last = i;
        }
      }

      ans = min(ans, n - last - 1);

      if(last == -1) cout<<-1<<endl;
      else cout<<ans<<endl;
    }

    return 0;
}
