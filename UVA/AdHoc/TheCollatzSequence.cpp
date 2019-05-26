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
	long a,L,i = 0;
	cin>>a>>L;
	while(a >= 0 && L >= 0){
		i++;
		long aux = a;
		int n = 0;
		while(a != 1  && a <= L){
			if(a % 2 == 0) a = a/2;
			else  a = 3*a +1;
			n++;
		}
		if(a == 1) n++;
		cout<<"Case "<<i<<": A = "<<aux<<", limit = "<<L<<", number of terms = "<<n<<endl;
		cin>>a>>L;
	}
    return 0;
}