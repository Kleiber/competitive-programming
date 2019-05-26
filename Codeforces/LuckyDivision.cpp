#include <iostream>

using namespace std;
int M[14] = {4,7,44,74,47,77,444,744,474,774,447,747,477,777};
int main()
{
    int n,b = 0;
    cin>> n;
    for(int i=0;i<14;i++){
        if(n % M[i] == 0) b = 1;
    }
	if(b == 0) cout<<"NO";
	else cout<<"YES";
    return 0;
}
