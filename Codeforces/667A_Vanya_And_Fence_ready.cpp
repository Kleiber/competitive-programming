/**
*  Generated by tpp tool
*  File: 667A_Vanya_And_Fence.cpp
*  Created: 29-03-2024 02:06:48
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

    int n, h;
    cin>>n>>h;

    int sum =0;

    for(int i = 0; i < n; i++) {
      int a;
      cin>>a;

      if(a > h) sum += 2;
      else sum += 1;
    }

    cout<<sum<<endl;

    return 0;
}

