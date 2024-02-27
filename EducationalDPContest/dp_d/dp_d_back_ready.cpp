/**
*  Generated by tpp tool
*  File: dp_d_back.cpp
*  Created: 26-02-2024 23:23:26
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


const int MAX = 1e2+5;
const int INF = 1e9+7;

int N, W;
int w[MAX], v[MAX];

long long solve(int pos, int weight) {
  if(weight < 0) return -INF;
  if(weight == 0 || pos > N) return 0;

  long long take = v[pos] + solve(pos + 1, weight - w[pos]);
  long long dont_take = solve(pos + 1, weight);

  return max(take, dont_take);
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>W;

    for(int i = 1; i <= N; i++) cin>>w[i]>>v[i];

    cout<<solve(1, W)<<endl;

    return 0;
}
