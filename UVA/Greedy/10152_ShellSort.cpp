#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> M;

bool order(string a, string b){
    return M[a] > M[b];
}

int main(){  
    int K;
    cin>>K;

    while(K--){
        int n;
        string s;
        cin>>n;
        getline(cin, s);
        
        vector<string> A(n), B(n);
        for(int i = 0; i < n; i++) getline(cin, A[i]);

        M.clear();

        for(int i = 0; i < n; i++){
            getline(cin, B[i]);
            M[B[i]] = i;
        }

        int dist = 0;
        vector<string> ans;

        for(int i = n - 1; i >= 0; i--){
            if(i + dist != M[A[i]]){
                ans.push_back(A[i]);
                dist++;
            }
        }

        sort(ans.begin(), ans.end(), order);
        for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<endl;
        cout<<endl;

    }
    return 0;
}