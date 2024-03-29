/**
*  Generated by tpp tool
*  File: 339A_Helpful_Maths.cpp
*  Created: 29-03-2024 01:38:57
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

    string s;
    cin>>s;

    vector<int> V;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] != '+') V.push_back(s[i] - '0');
    }

    sort(V.begin(), V.end());

    for(int i = 0; i < V.size(); i++) {
      if(i > 0) cout<<"+";
      cout<<V[i];
    }
    cout<<endl;

    return 0;
}
