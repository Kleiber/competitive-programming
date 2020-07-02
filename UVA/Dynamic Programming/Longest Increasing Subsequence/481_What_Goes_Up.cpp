#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> A, L, M, P;
int len, it, num;

int main(){
   len = it = 0;

   while(cin>>num){
        int ind = A.size();
        A.push_back(num);
        
        int pos = lower_bound(L.begin(), L.end(), num) - L.begin();
        if (pos == L.size()){
            L.push_back(num);
            M.push_back(ind);
        }else{
            L[pos] = num;
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

   cout<<len<<endl;
   cout<<"-"<<endl;

   while(!S.empty()){
      cout<<S.top()<<endl;
      S.pop();
   }

   return 0;
}