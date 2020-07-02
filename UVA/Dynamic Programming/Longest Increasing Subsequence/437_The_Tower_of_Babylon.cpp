#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct block{
    int x, y, z;
};

bool order(block a, block b){
    if(a.x != b.x) return a.x < b.x;
    else{
        if(a.y != b.y) return a.y < b.y;
        else return a.z < b.z;
    }
}

int main(){
    int cases = 1;
    int n;
    while(cin>>n && n){

        vector<block> V;
        for(int i = 0; i < n; i++){
            int x, y, z;
            cin>>x>>y>>z;
            V.push_back((block){x, y, z});
            V.push_back((block){x, z, y});
            V.push_back((block){y, x, z});
            V.push_back((block){y, z, x});
            V.push_back((block){z, x, y});
            V.push_back((block){z, y, x});
        }

        sort(V.begin(), V.end(), order);

        vector<int> L(V.size());
        int len = 0;

        for(int i = 0; i < V.size(); i++){
            L[i] = V[i].z;

            for(int j = 0; j < i; j++){
                if((V[i].x > V[j].x && V[i].y > V[j].y) || (V[i].x > V[j].y && V[i].y > V[j].x)){
                    L[i] = max(L[i], L[j] + V[i].z);
                }
            }

            len = max(len, L[i]);
        }

        cout<<"Case "<<cases++<<": maximum height = "<<len<<endl;
    }

    return 0;
}
