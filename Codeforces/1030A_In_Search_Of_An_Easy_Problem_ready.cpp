/**
*  Generated by tpp tool
*  File: 1030A_In_Search_Of_An_Easy_Problem.cpp
*  Created: 29-03-2024 02:25:41
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
    cin>>n;

    for(int i = 0; i < n; i++) {
      int num;
      cin>>num;

      if(num) {
        cout<<"HARD"<<endl;
        return 0;
      }
    }

    cout<<"EASY"<<endl;
    return 0;
}

