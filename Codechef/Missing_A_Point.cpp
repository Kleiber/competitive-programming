#include<iostream>
#include<vector>
using namespace std;

int main(){
    int T, N, x, y;
    cin>>T;

    while(T--) {
        cin>>N;

        pair<int,int> ans;
        
        for(int i = 0; i < 4*N - 1; i++) {
            cin>>x>>y;
            ans.first ^= x;
            ans.second ^= y;
        }

        cout<<ans.first<<" "<<ans.second<<endl;
    }

    return 0;
}