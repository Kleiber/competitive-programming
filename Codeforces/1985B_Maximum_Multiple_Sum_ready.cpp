/**
*  Generated by tpp tool
*  File: 1985B_Maximum_Multiple_Sum.cpp
*  Created: 18-06-2024 08:52:44
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
      int n;
      cin>>n;

      int maximum = -1;
      int ans = -1;

      int i = n;
      while(i > 1) {
        int size = n/i;
        int sum = i * size * (size + 1) / 2;

        if(sum > maximum) {
          maximum = sum;
          ans = i;
        }

        i--;
      }

      cout<<ans<<endl;
    }

    return 0;
}

