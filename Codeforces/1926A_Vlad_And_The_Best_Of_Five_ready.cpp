/**
*  Generated by tpp tool
*  File: 1926A_Vlad_And_The_Best_Of_Five.cpp
*  Created: 21-02-2024 16:17:28
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

    int cases;
    cin>>cases;

    while(cases--) {
      string word;
      cin>>word;

      int letterA = 0;
      int letterB = 0;
      for(int i = 0; i < word.size(); i++) {
        if(word[i] == 'A') letterA++;
        if(word[i] == 'B') letterB++;
      }

      if(letterA > letterB) cout<<"A"<<endl;
      else cout<<"B"<<endl;
    }

    return 0;
}
