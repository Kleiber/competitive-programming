/**
*  Generated by tpp tool
*  File: sorttwonumbers.cpp
*  Created: 16-08-2021 23:42:09
**/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
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

    int a;
    int b;

    while(cin>>a>>b) {
        if (a < b) cout<<a<<" "<<b<<endl;
        else cout<<b<<" "<<a<<endl;
    }

    return 0;
}
