/**
*  Generated by tpp tool
*  File: 977A_Wrong_Subtraction.cpp
*  Created: 29-03-2024 01:52:48
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

    int n, k;
    cin>>n>>k;

    for(int i = 0; i < k; i++) {
      if(n % 10) n = n - 1;
      else n = n/10;

      if(n == 0) break;
    }

    cout<<n<<endl;

    return 0;
}

