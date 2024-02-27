/**
*  Generated by tpp tool
*  File: dp_h_back.cpp
*  Created: 27-02-2024 12:58:48
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


#define WALL '#'

const int MOD = 1e9+7;

int H, W;
vector<string> grid;

bool isValid(int r, int c) {
  return r >= 0 && r < H && c >= 0 && c < W;
}

int solve(int r, int c) {
  if(!isValid(r, c)) return 0;
  if(grid[r][c] == WALL) return 0;
  if(r == H - 1 && c == W - 1) return 1;

  int count = 0;

  count = (count + solve(r + 1, c)) % MOD;
  count = (count + solve(c, r + 1)) % MOD;

  return count;
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>H>>W;

    grid = vector<string>(H);

    for(int i = 0; i < H; i++) cin>>grid[i];

    cout<<solve(0, 0)<<endl;

    return 0;
}
