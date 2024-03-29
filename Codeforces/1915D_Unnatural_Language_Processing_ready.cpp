/**
*  Generated by tpp tool
*  File: 1915D_Unnatural_Language_Processing.cpp
*  Created: 28-12-2023 11:58:23
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


// CV
// ba be ca ce da de
// CVC
// bab bac bad
// beb bec bed
// cac cab cad
// cec ceb ced
// dad dab dac
// ded deb dec

unordered_map<string, bool> M;

void fillMap() {
  M["ba"] = 1;
  M["be"] = 1;
  M["ca"] = 1;
  M["ce"] = 1;
  M["da"] = 1;
  M["de"] = 1;
  M["bab"] = 1;
  M["bac"] = 1;
  M["bad"] = 1;
  M["beb"] = 1;
  M["bec"] = 1;
  M["bed"] = 1;
  M["cac"] = 1;
  M["cab"] = 1;
  M["cad"] = 1;
  M["cec"] = 1;
  M["ceb"] = 1;
  M["ced"] = 1;
  M["dad"] = 1;
  M["dab"] = 1;
  M["dac"] = 1;
  M["ded"] = 1;
  M["deb"] = 1;
  M["dec"] = 1;
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    fillMap();

    int t;
    cin>>t;

    while(t--){
      int n;
      string s;
      cin>>n;
      cin>>s;

      string ans = "";

      int ind = n - 1;
      while(ind >= 0) {
        string first = "";
        first = s[ind] + first;
        first = s[ind - 1] + first;

        string second = "";
        second = s[ind] + second;
        second = s[ind - 1] + second;
        second = s[ind - 2] + second;

        if(M[first]) {
          ans += s[ind];
          ans += s[ind - 1];
          ind = ind - 2;
          if(ind > 0) ans  += '.';
          continue;
        }
        if(M[second]) {
          ans += s[ind];
          ans += s[ind - 1];
          ans += s[ind - 2];
          ind = ind - 3;
          if(ind > 0) ans += '.'; 
          continue;
        }
      }

      reverse(ans.begin(), ans.end()); 
      cout<<ans<<endl;

    }

    return 0;
}
