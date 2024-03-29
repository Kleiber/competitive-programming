/**
*  Generated by tpp tool
*  File: 863B_Kayaking.cpp
*  Created: 14-02-2024 00:12:34
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


#define MAX 50005

bool order(int a, int b) {
  return a < b;
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> V(2*n);
    for(int i = 0; i < 2*n; i++) cin>>V[i];

    sort(V.begin(), V.end(), order);

    int ans = MAX;

    for(int i = 0; i < 2*n; i++) {
      for(int j = i + 1; j < 2*n; j++) {
        vector<int> new_V;
        int sum = 0;

        for(int k = 0; k < 2*n; k++) {
          if(k != i && k != j) new_V.push_back(V[k]);
        }

        for(int k = 0; k < 2*n - 2; k+=2) sum += abs(new_V[k] - new_V[k + 1]);

        ans = min(ans, sum);
      }
    }

    cout<<ans<<endl;
    return 0;
}

