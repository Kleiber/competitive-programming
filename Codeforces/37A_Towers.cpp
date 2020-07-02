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
int main()
{
    
    vector<int>v(1000,0);
    int n,a,ans1 = 0,ans2 = 0;
    cin>>n;
    for(int i = 0; i < n ; i++){
        cin>> a;
        v[a - 1]++;
    }
    
    for(int j = 0 ; j < v.size() ; j++){
        if(v[j]!= 0) ans2++;
        if(v[j] > ans1) ans1 = v[j];
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}