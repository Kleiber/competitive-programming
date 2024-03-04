/**
*  Generated by tpp tool
*  File: abc343_d_Diversity_Of_Scores.cpp
*  Created: 03-03-2024 17:42:29
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

    int N, T;
    cin>>N>>T;

    vector<long long> V(N, 0);
    unordered_map<long long, int> M;

    M[0] = N;

    for(int i = 0; i < T; i++) {
      int A, B;
      cin>>A>>B;

      long long prev, curr;

      prev = V[A - 1];
      V[A - 1] += B;
      curr = V[A - 1];

      if(M[prev] - 1 == 0) M.erase(prev);
      else M[prev]--;
      M[curr]++;

      cout<<M.size()<<endl;
    }

    return 0;
}
