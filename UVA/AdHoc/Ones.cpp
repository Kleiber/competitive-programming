#include <iostream>
 using namespace std;
int main(){
    long N, n, r, f;
    while (cin>>n) {
        N = r = f = 1;
        while (f) {
            if ( N < n ) {
                N = ( N * 10 ) + 1;
                r++;
            }
            f = N % n;
            N = f;
        } 
        cout<<r<<endl;
    }
 
    return 0;
}