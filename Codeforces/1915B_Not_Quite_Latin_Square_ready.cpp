/**
*  Generated by tpp tool
*  File: 1915B_Not_Quite_Latin_Square.cpp
*  Created: 28-12-2023 11:41:06
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
using namespace std;


int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
      vector<string> V(3);
      for(int i = 0; i < 3; i++) cin>>V[i];

      vector<int> count(3);
      for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
          if(V[i][j] == '?') {
            for(int c = 0; c < 3; c++) {
              if(V[i][c] != '?') count[V[i][c] - 'A']++;
            }
            for(int r = 0; r < 3; r++) {
              if(V[r][j] != '?') count[V[r][j] - 'A']++;
            }
          }
        }
      }

      for(int i = 0; i < 3; i++) {
        if(count[i] == 0) cout<<(char)(i + 'A')<<endl;
      }
    }

    return 0;
}

