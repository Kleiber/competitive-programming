#include <stdio.h>
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
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;
int main(){
    string s;
    int H, M, S, C, total,ans;
    while(cin>>s){
        H = (s[0] - '0')*10 + (s[1] - '0');
        M = (s[2] - '0')*10 + (s[3] - '0');
        S = (s[4] - '0')*10 + (s[5] - '0');
        C = (s[6] - '0')*10 + (s[7] - '0');
        total = (H*3600 + M*60 + S)*100 + C;
        ans = (125 * total) / 108;
        printf("%07d\n", ans);
    }
    return 0;
}