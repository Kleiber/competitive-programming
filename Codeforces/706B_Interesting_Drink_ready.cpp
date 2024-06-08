/**
*  Generated by tpp tool
*  File: 706B_Interesting_Drink.cpp
*  Created: 08-06-2024 08:24:50
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

    int n, q, x;
    cin>>n;

    vector<int> V(n);
    for(int i = 0; i < n; i++) cin>>V[i];

    sort(V.begin(), V.end());

    cin>>q;

    for(int i = 0; i < q; i++) {
      cin>>x;

      int pos = upper_bound(V.begin(), V.end(), x) - V.begin();
      cout<<pos<<endl;
    }

    return 0;
}

