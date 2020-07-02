#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int LIS(vector<int> &A, vector<int> &W){

    int N = A.size();
    vector<int> L(N);

    int width = 0;
    for(int i = 0; i < A.size(); i++){
        L[i] = W[i];
        for(int j = 0; j < i; j++){
            if(A[i] > A[j]) L[i] = max(L[i], L[j] + W[i]);
        }

        width = max(width, L[i]);
    }

    return width;
}

int main(){
    int C;
    cin>>C;

    for(int cases = 1; cases <= C; cases++){

        int N;
        cin>>N;

        vector<int> A(N);
        vector<int> W(N);
        for(int i = 0; i < N; i++) cin>>A[i];
        for(int i = 0; i < N; i++) cin>>W[i];

        int widthA = LIS(A, W);
        reverse(A.begin(), A.end());
        reverse(W.begin(), W.end());
        int widthD = LIS(A, W);

        if(widthA >= widthD) cout<<"Case "<<cases<<". Increasing ("<<widthA<<"). Decreasing ("<<widthD<<")."<<endl;
        else cout<<"Case "<<cases<<". Decreasing ("<<widthD<<"). Increasing ("<<widthA<<")."<<endl;
    }
    return 0;
}