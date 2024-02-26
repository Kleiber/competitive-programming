/**
*  Generated by tpp tool
*  File: dp_a_back.cpp
*  Created: 26-02-2024 19:03:39
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


const int INF = 1e9+7;
const int MAX = 1e5+5;

int n;
int h[MAX];

long long solve(int pos) {
  if(pos > n) return INF;
  if(pos == n) return 0;

  long long cost1 = abs(h[pos + 1] - h[pos]);
  long long cost2 = abs(h[pos + 2] - h[pos]);

  return min(cost1 + solve(pos + 1), cost2 + solve(pos + 2));
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for(int i = 1 ; i <= n; i++) cin>>h[i];

    cout<<solve(1)<<endl;

    return 0;
}
