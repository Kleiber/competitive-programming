#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LIS(vector<int> &A, vector<int> &len){

    vector<int> L;

    for(int ind = 0; ind < A.size(); ind++){

        int pos = lower_bound(L.begin(), L.end(), A[ind]) - L.begin();
        if(pos == L.size()) L.push_back(A[ind]);
        else L[pos] = A[ind];

        len[ind] = pos + 1;
    }
}

int main(){
    int N;
    while(cin>>N){

        vector<int> A(N);
        vector<int> lenA(N), lenD(N);
        for(int i = 0; i < N; i++) cin>>A[i];

        LIS(A, lenA);
        reverse(A.begin(), A.end());
        LIS(A, lenD);

        int len = 1;
        for(int i = 0; i < N; i++){
            int lowest = min(lenA[i], lenD[N - 1 - i]);
            len = max(len, lowest*2 - 1);
        }

        cout<<len<<endl;
    }
    return 0;
}