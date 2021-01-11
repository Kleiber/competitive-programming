/**
*  Generated by tpp tool
*  File: awkwardparty.cpp
*  Created: 07-10-2020 22:22:15
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    unordered_map<int, int> M;

    int ans = n;
    for(int i = 1; i <= n; i++) {
    	int num;
    	cin>>num;

    	if(M[num] == 0) M[num] = i;
    	else {
    		ans = min(ans, i - M[num]);
    		M[num] = i;
    	}
    }

    cout<<ans<<endl;
 
    return 0;
}