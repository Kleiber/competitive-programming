/**
*  Generated by tpp tool
*  File: 1968B_Prefiquence.cpp
*  Created: 04-05-2024 20:41:09
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
      int n, m;
      string a, b;

      cin>>n>>m;
      cin>>a;
      cin>>b;

      int k = 0;
      for(int i = 0; i < m; i++) {
        if(k == n) break;
        if(b[i] == a[k]) k++;
      }

      cout<<k<<endl;
    }

    return 0;
}

