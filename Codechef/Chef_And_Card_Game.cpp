#include<iostream>
using namespace std;

int sum(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); i++) ans += s[i] - '0';
    return ans;
}

int main() {
    int T, N;
    cin>>T;
    while(T--) {
        cin>>N;
        
        int a = 0;
        int b = 0;

        string A, B;
        for(int i = 0; i < N; i++) {
            cin>>A>>B;
            int sumA = sum(A);
            int sumB = sum(B);

            if (sumA == sumB){
                a++;
                b++;
            } else {
                if(sumA > sumB) a++;
                else b++;
            }
        }

        if(a == b) cout<<2<<" "<<a<<endl;
        else {
            if(a > b) cout<<0<<" "<<a<<endl;
            else cout<<1<<" "<<b<<endl;
        }
    }
    return 0;
}