/**
*  Generated by tpp tool
*  File: 1933C_Count_The_Values_Of_K.cpp
*  Created: 27-02-2024 22:48:21
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
      int a, b, l;
      cin>>a>>b>>l;

      set<int> S;

      for(int i = 0; pow(a, i) <= l; i++) {
        for(int j = 0; pow(b, j) <= l; j++) {
          int prod = pow(a, i) * pow(b, j);

          if(l % prod == 0) S.insert(l /prod);
        }
      }

      cout<<S.size()<<endl;
    }

    return 0;
}

