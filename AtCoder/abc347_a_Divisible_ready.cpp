/**
*  Generated by tpp tool
*  File: abc347_a_Divisible.cpp
*  Created: 30-03-2024 09:21:33
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

    vector<int> V;

    for(int i = 0; i < n; i++) {
      int a;
      cin>>a;

      if(a % k == 0) V.push_back(a/k);
    }

    sort(V.begin(), V.end());

    for(int i = 0; i < V.size(); i++) {
      if(i > 0) cout<<" ";
      cout<<V[i];
    }
    cout<<endl;

    return 0;
}

