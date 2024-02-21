/**
*  Generated by tpp tool
*  File: 1926D_Vlad_And_Division.cpp
*  Created: 21-02-2024 16:46:19
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


#define MAX 31

int diff(string a, string b) {
  int cont = 0;
  for(int i = 0; i < MAX; i++) {
    if(a[i] != b[i]) cont++;
  }

  return cont;
}

string getBits(long long int num) {
  string tmp = "";
  int size = 0;

  while(num && size < MAX) {
    if(num & 1) tmp += '1';
    else tmp += '0';

    num>>=1;
    size++;
  }

  string bits = "";
  for(int i = MAX - 1 ; i >= 0 ; i--) {
    if(i < tmp.size()) bits += tmp[i];
    else bits += '0';
  }

  return bits;
}

string getComplement(string s) {
  string bits = "";
  for(int i = 0; i < MAX; i++) {
    if(s[i] == '1') bits += '0';
    else bits += '1';
  }

  return bits;
}

bool order(pair<string, string> p1, pair<string, string> p2) {
  return p1.second < p2.second;
}


int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases;
    cin>>cases;

    while(cases--) {
      int n;
      cin>>n;

      set<string> V, R;
      map<string, int> M;
      for(int i = 0; i < n; i++) {
        long long num;
        cin>>num;

        string base2 = getBits(num);
        string comp2 = getComplement(base2);
        
        V.insert(base2);
        R.insert(comp2);
        M[base2]++;
      }

      vector<string> S(R.begin(), R.end());
      map<string, bool> visited;
      long long ans = n;

      for(auto s: V) {
        if(!visited[s]) {
          if(binary_search(S.begin(), S.end(), s)) {
            string ss = getComplement(s);

            visited[s] = 1;
            visited[ss] = 1;
            ans -= min(M[s], M[ss]);
          }
        }
      }

      cout<<ans<<endl;
    }

    return 0;
}
