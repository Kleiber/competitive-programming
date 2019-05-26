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
#include <cstring>
using namespace std;
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	cout<<min(n-a,b+1);
    return 0;
}