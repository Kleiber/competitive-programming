/**
*  Generated by tpp tool
*  File: 69A_Young_Physicist.cpp
*  Created: 16-04-2024 15:16:06
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

    int n;
    cin>>n;

    vector<int> V(3, 0);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 3; j++) {
        int num;
        cin>>num;

        V[j] += num;
      }
    }

    bool isZero = 1;
    for(int i = 0; i < 3; i++) {
      if(V[i] != 0) {
        isZero = 0;
        break;
      }
    }

    if(isZero) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
