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
	int i,f;
	while(1){
		cin>>i>>f;
		if(i == -1 && f == -1) break;
		int ans=abs(i-f);
        if(ans >= 50)
        ans = 100 - ans;
        cout<<ans<<endl;;
	}
	return 0;
}