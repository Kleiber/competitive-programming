/**
*  Generated by tpp tool
*  File: 1915A_Odd_One_Out.cpp
*  Created: 28-12-2023 11:35:55
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
using namespace std;


int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, a, b, c;
    cin>>t;

    while(t--) {
      cin>>a>>b>>c;
      int ans = a ^ b ^ c;
      cout<<ans<<endl;
    }

    return 0;
}

