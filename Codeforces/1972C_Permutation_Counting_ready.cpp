/**
*  Generated by tpp tool
*  File: 1972C_Permutation_Counting.cpp
*  Created: 30-04-2024 13:28:04
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
      long long int n, k;
      cin>>n>>k;

      vector<long long int> A(n + 1);
      for(int i = 1; i <= n; i++) cin>>A[i];

      sort(A.begin(), A.end());

      long long int frequency = A[1];
      long long int changes = 1;

      for(int i = 1; i < n; i++) {
        long long int diff = A[i + 1] - A[i];
        if(changes*diff > k) break;
        
        k -= i*diff;
        frequency = A[i + 1];
        changes++;
      }

      frequency = frequency + k/changes;
      long long int ans = (frequency*n - changes) + (k % changes + 1);

      cout<<ans<<endl;
    }

    return 0;
}

