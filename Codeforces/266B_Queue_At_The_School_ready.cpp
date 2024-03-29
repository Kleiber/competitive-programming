/**
*  Generated by tpp tool
*  File: 266B_Queue_At_The_School.cpp
*  Created: 29-03-2024 17:35:08
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

    int n, t;
    string s;

    cin>>n>>t;
    cin>>s;

    for(int i = 1; i <= t; i++) {
      for(int k = 1; k < s.size(); k++) {
        if(s[k] == 'G' && s[k - 1] == 'B') {
          swap(s[k], s[k - 1]);
          k++;
        }
      }
    }

    cout<<s<<endl;

    return 0;
}

