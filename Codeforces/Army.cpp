#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
        int n;
        cin>>n;
        int d[n];
        for( int i=0; i<(n-1); i++){
                cin>>d[i];
        }
        int a,b;
        cin>>a>>b;
        int r=0;
        for(int k=(a-1); k<(b-1);k++){
                r+=d[k];
        }
        cout<<r;
		return 0;
}