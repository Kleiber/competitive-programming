#include<iostream>
using namespace std;

int main() {
    int T, N;
    cin>>T;
    while(T--) {
        int a, b;
        int ans = 0;
        cin>>N>>a;
        for(int i = 1; i < N; i++) {
            cin>>b;
            ans += abs(a - b) - 1;
            a = b;
        }

        cout<<ans<<endl;
    }
    return 0;
}