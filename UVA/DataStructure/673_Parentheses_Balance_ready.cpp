/**
*  Generated by tpp tool
*  File: 673_Parentheses_Balance.cpp
*  Created: 11-01-2024 14:47:23
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

    int n;
    string s;

    cin>>n;
    getline(cin, s);

    while(n--) {
      getline(cin, s);

      stack<char> S;
      bool isCorrect = 1;

      for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] == '[') S.push(s[i]);
        else {
          if(s[i] == ')') {
            if(!S.empty() && S.top() == '(') {
              S.pop();
              continue;
            }
            isCorrect = 0;
            break;
          }

          if(s[i] == ']') {
            if(!S.empty() && S.top() == '[') {
              S.pop();
              continue;
            }
            isCorrect = 0;
            break;
          }
        }
      }

      if(isCorrect && S.empty()) cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
    }

    return 0;
}
