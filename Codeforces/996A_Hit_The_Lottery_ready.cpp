/**
*  Generated by tpp tool
*  File: 996A_Hit_The_Lottery.cpp
*  Created: 16-04-2024 17:59:05
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

    vector<int> V = {100, 20, 10, 5, 1};

    int n;
    cin>>n;

    int ans = 0;
    for(int i = 0; i < V.size(); i++) {
      ans += n / V[i];
      n = n % V[i];  
    }

    cout<<ans<<endl;

    return 0;
}
