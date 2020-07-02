#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int cases = 1;
    int num;
    while(cin>>num){
        
        if(num == -1) break;
        if(cases != 1) cout<<endl;

        vector<int> A;
        A.push_back(num);
        while(cin>>num){
            if(num == -1) break;
            A.push_back(num);
        }

        vector<int> L, M, P;
        int len, it;

        len = it = 0;
        for(int ind = A.size() - 1; ind >= 0; ind--){

            int pos = lower_bound(L.begin(), L.end(), A[ind]) - L.begin();
            if (pos == L.size()){
                L.push_back(A[ind]);
                M.push_back(ind);
            }else{
                L[pos] = A[ind];
                M[pos] = ind;
            }
      
            P.push_back(pos? M[pos - 1] : -1);
        
            if(pos + 1 >= len) {
                len = pos + 1;
                it = ind;
            }
        }

        stack<int> S;
        while(P[it] >= 0){
            S.push(A[it]);
            it = P[it];
        }
        S.push(A[it]);

        cout<<"Test #"<<cases++<<":"<<endl;
        cout<<"  maximum possible interceptions: "<<len<<endl;
    }

    return 0;
}