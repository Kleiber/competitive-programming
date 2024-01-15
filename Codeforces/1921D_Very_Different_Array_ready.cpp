/**
*  Generated by tpp tool
*  File: 1921D_Very_Different_Array.cpp
*  Created: 15-01-2024 12:50:08
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


bool order(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.first > p2.first;
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases;
    cin>>cases;

    while(cases--) {
      int n, m;
      cin>>n>>m;

      vector<long long> N(n), M(m);
      for(int i = 0; i < n; i++) cin>>N[i];
      for(int i = 0; i < m; i++) cin>>M[i];

      sort(N.begin(), N.end());
      sort(M.begin(), M.end());

      vector<pair<long long, long long>> V;
      for(int i = 0; i < n; i++) {
        V.push_back(make_pair(abs(M[m - i - 1] - N[i]), i));
        V.push_back(make_pair(abs(M[i] - N[n - i - 1]), n - i - 1));
      }

      sort(V.begin(), V.end(), order);

      vector<bool> used(n, 0);
      long long ans = 0;
      for(pair<long long, long long> p : V) {
        if(used[p.second]) continue;
        used[p.second] = 1;
        ans += p.first;
      }

      cout<<ans<<endl;
    }

    
    return 0;
}
