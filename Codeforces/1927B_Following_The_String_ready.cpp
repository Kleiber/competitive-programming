/**
*  Generated by tpp tool
*  File: 1927B_Following_The_String.cpp
*  Created: 06-02-2024 15:59:27
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

      vector<queue<char>> V(n);
      string ans(n, '.');
      char next = 'a';

      for(int i = 0; i < n; i++) {
        int a;
        cin>>a;

        if(a == 0) {
          ans[i] = next;

          V[a].push(next);
          next++;
        } else {
          char curr = V[a - 1].front();
          V[a - 1].pop();

          ans[i] = curr;
          V[a].push(curr);
        }
      }

      cout<<ans<<endl;
    }

    return 0;
}

