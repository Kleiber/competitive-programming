/**
*  Generated by tpp tool
*  File: 1950A_Stair_Peak_Or_Neither.cpp
*  Created: 28-03-2024 11:46:10
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
      int a, b, c;
      cin>>a>>b>>c;

      if(a < b && b < c) cout<<"STAIR"<<endl;
      else {
        if(a < b && b > c) cout<<"PEAK"<<endl;
        else cout<<"NONE"<<endl;
      }
    }

    return 0;
}

