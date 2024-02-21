/**
*  Generated by tpp tool
*  File: 1926B_Vlad_And_Shapes.cpp
*  Created: 21-02-2024 16:22:30
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
      int N;
      cin>>N;

      vector<string> V;
      for(int i = 0; i < N; i++) {
        string s;
        cin>>s;

        string aux = "";
        for(int j = 0; j < N; j++) {
          if(s[j] == '1') aux += s[j];
        }

        if(aux.size() > 0) V.push_back(aux);
      }

      if(V[0].size() == V[V.size() - 1].size()) cout<<"SQUARE"<<endl;
      else cout<<"TRIANGLE"<<endl;
    }

    return 0;
}

