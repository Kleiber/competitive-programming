/**
*  Generated by tpp tool
*  File: 1921C_Sending_Messages.cpp
*  Created: 15-01-2024 12:13:15
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

    int cases;
    cin>>cases;

    while(cases--) {
      long long int n, f, a, b;
      cin>>n>>f>>a>>b;

      vector<long long int> V(n + 1, 0);
      for(int i = 1; i <= n; i++) cin>>V[i];

      for(int i = 1; i <= n; i++) {
        long long int diff= V[i] - V[i - 1];
        f -= min(diff*a, b);
      }

      if(f > 0) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }

    return 0;
}

