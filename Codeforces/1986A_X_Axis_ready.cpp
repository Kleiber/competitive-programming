/**
*  Generated by tpp tool
*  File: 1986A_X_Axis.cpp
*  Created: 02-07-2024 14:06:07
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

    int t;
    cin>>t;

    while(t--) {
      vector<int> A(3);
      for(int i = 0; i < 3; i++) cin>>A[i];

      int ans = 100000;
      for(int i = 0; i < 3; i++) {
        int sum = 0;
        
        for(int j = 0;  j < 3; j++) sum += abs(A[j] - A[i]);

        ans = min(ans, sum);
      }

      cout<<ans<<endl;
    }

    return 0;
}
