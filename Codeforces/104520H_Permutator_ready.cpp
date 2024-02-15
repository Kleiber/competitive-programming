/**
*  Generated by tpp tool
*  File: 104520H_Permutator.cpp
*  Created: 14-02-2024 21:58:11
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

bool order(long long a, long long b) {
  return a > b;
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin>>n;

    vector<long long> a(n), b(n);

    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    for(long long i = 0; i < n; i++) {
      long long numOfSubArrays = (i + 1) * (n - i);
      a[i] = a[i] * numOfSubArrays;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), order);

    long long sum = 0;
    for(int i = 0; i < n; i++) sum += a[i]*b[i];

    cout<<sum<<endl;

    return 0;
}

