/**
*  Generated by tpp tool
*  File: 1950E_Nearly_Shortest_Repeating_Substring.cpp
*  Created: 28-03-2024 23:58:39
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


const int MAX = 2e5 + 5;

vector<vector<int>> dividers;

void sieve() {
  dividers = vector<vector<int>>(MAX);

  for(int i = 1; i < MAX; i++) {
    for(int j = i; j < MAX; j += i) {
      dividers[j].push_back(i);
    }
  }
}

int diff(string s1, string s2) {
  int cont = 0;

  for(int i = 0; i < s1.size(); i++) {
    if(s1[i] != s2[i]) cont++;
  }

  return cont;
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int t;
    cin>>t;

    while(t--) {
      int n, ans;
      string source, target, pattern;

      cin>>n;
      cin>>source;

      for(int i = 0; i < dividers[n].size(); i++) {
        int len = dividers[n][i];

        pattern = source.substr(0, len);
        target = "";
        for(int k = 0; k < n/len; k++) target += pattern;

        if(diff(source, target) <= 1) {
          ans = len;
          break;
        }

        pattern = source.substr(len, len);
        target = "";
        for(int k = 0; k < n/len; k++) target += pattern;

        if(diff(source, target) <= 1) {
          ans = len;
          break;
        }
      }

      cout<<ans<<endl;
    }

    return 0;
}

