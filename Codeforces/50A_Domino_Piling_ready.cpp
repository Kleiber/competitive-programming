/**
*  Generated by tpp tool
*  File: 50A_Domino_Piling.cpp
*  Created: 29-03-2024 01:31:37
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

    int M, N;
    cin>>M>>N;

    int up = M * (N/2);
    int down = (N % 2) * M/2;

    int ans = up + down;
    cout<<ans<<endl;

    return 0;
}

