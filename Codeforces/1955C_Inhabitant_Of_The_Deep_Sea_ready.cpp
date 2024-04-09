/**
*  Generated by tpp tool
*  File: 1955C_Inhabitant_Of_The_Deep_Sea.cpp
*  Created: 08-04-2024 12:24:57
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
#include <deque>

using namespace std;


int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--) {
      int n, k;
      cin>>n>>k;

      vector<int> V(n);
      long long int sum = 0;

      for(int i = 0; i < n; i++) {
        cin>>V[i];
        sum += V[i];
      }

      int ans = 0;

      if(sum <= k) ans = n;
      else {
        int leftSum = (k + 1)/2;
        int rightSum = k/2;

        int left = 0;
        int right = n - 1;

        while(V[left] <= leftSum) {
          leftSum -= V[left];
          left++;
        }

        while(V[right] <= rightSum) {
          rightSum -= V[right];
          right--;
        }

        ans = (n - 1) - (right - left);
      }

      cout<<ans<<endl;
    }

    return 0;
}

