#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10000

int A[MAX], tree[4*MAX], lazy[4*MAX];

void build(int node, int L, int R){
    if(L == R) tree[node] = A[L];
    else{
        build(2*node, L, (L + R)/2);
        build(2*node + 1, (L + R)/2 + 1, R);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

int query(int node, int L, int R, int l, int r){
    
    if(L > r || R < l) return -1;

    if(lazy[node] != 0){
        tree[node] += (R - L + 1) * lazy[node];

        if(L != R){
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if(L >= l && R <= r) return tree[node];

    int val1 = query(2*node, L, (L + R)/2, l, r);
    int val2 = query(2*node + 1, (L + R)/2 + 1, R, l, r);
    return val1 + val2;
}

void update(int node, int L, int R, int l, int r, int val){

    if(lazy[node] != 0) { 
        tree[node] += (R - L + 1) * lazy[node];

        if(L != R){
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if(L > r || R < l) return;

    if(L >= l && R <= r){
        tree[node] += (R - L + 1) * val;

        if(L != R){
            lazy[2*node] += val;
            lazy[2*node + 1] += val;
        }

        return;
    }

    update(2*node, L, (L + R)/2, l, r, val);
    update(2*node + 1, (L + R)/2 + 1, R, l, r, val);
    tree[node] = tree[2*node] + tree[2*node + 1];
}

int main(){
    
    memset(A, 0, sizeof(A));
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));

    int N = 8;

    for(int i = 0; i < N; i++) A[i] = i + 1;

    build(1, 0, N - 1);

    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<tree[i]<<") ";
    cout<<endl;
    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<lazy[i]<<") ";
    cout<<endl;

    update(1, 0, N - 1, 0, 3, 3);
    cout<<endl;

    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<tree[i]<<") ";
    cout<<endl;
    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<lazy[i]<<") ";
    cout<<endl;

    update(1, 0, N - 1, 0, 3, 1);
    cout<<endl;

    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<tree[i]<<") ";
    cout<<endl;
    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<lazy[i]<<") ";
    cout<<endl;

    update(1, 0, N - 1, 0, 0, 2);
    cout<<endl;

    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<tree[i]<<") ";
    cout<<endl;
    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<lazy[i]<<") ";
    cout<<endl;

    
    update(1, 0, N - 1, 3, 5, 6);
    cout<<endl;

    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<tree[i]<<") ";
    cout<<endl;
    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<lazy[i]<<") ";
    cout<<endl;

    cout<<query(1, 0 , N - 1, 4, 6)<<endl;
    cout<<endl;

    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<tree[i]<<") ";
    cout<<endl;
    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<lazy[i]<<") ";
    cout<<endl;

    cout<<query(1, 0 , N - 1, 2, 4)<<endl;
    cout<<endl;

    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<tree[i]<<") ";
    cout<<endl;
    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<lazy[i]<<") ";
    cout<<endl;

    cout<<query(1, 0 , N - 1, 5, 6)<<endl;
    cout<<endl;

    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<tree[i]<<") ";
    cout<<endl;
    for(int i = 0; i < 16; i++) cout<<"("<<i<<","<<lazy[i]<<") ";
    cout<<endl;
}