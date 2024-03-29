/**
*  Generated by tpp tool
*  File: 1934A_Too_Min_Too_Max.cpp
*  Created: 01-03-2024 11:57:24
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
      int n;
      cin>>n;

      vector<long long> A(n);
      for(int i = 0; i < n; i++) cin>>A[i];

      sort(A.begin(), A.end());

      int ai = A[n - 1];
      int aj = A[0];
      int ak = A[n - 2];
      int al = A[1];

      long long ans = abs(ai - aj) + abs(aj - ak) + abs(ak - al) + abs(al - ai);

      cout<<ans<<endl;
    }

    return 0;
}

