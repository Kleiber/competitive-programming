#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 200010;

int n;
int num[MAXN];
int treeNum[MAXN];
bool isSelect[MAXN];

int lowbit(int x){
    return x&(-x);
}

int getSum(int x){
    int sum = 0;
    while(x){
         sum += treeNum[x];
         x -= lowbit(x);
    }
    return sum;
}

void add(int x , int val){
    while(x < MAXN){
         treeNum[x] += val;
         x += lowbit(x);
    }
}

void init(){
    memset(isSelect , false , sizeof(isSelect));
    memset(treeNum , 0 , sizeof(treeNum));
    for(int i = 1 ; i <= n ; i++)
        add(i , 1);
}

int search(int x){
    int left = 1;
    int right = n;
    while(left <= right){
         int mid = (left+right)>>1;
         int sum = getSum(mid);
         if(sum == x){
             if(!isSelect[mid]) 
                 return mid;
             right = mid-1; 
         }
         else if(sum < x)
             left = mid+1;
         else
             right = mid-1;
    }
}

void solve(){
    init();
    int output[MAXN];
    for(int i = n ; i >= 1 ; i--){
        int x = i-num[i];
        int ans = search(x);
        output[i] = ans;
        isSelect[ans] = true;
        add(ans , -1);
    }
    printf("%d" , output[1]);
    for(int i = 2 ; i <= n ; i++)
        printf(" %d" , output[i]);
    puts("");
}

int main(){
    int cas;
    scanf("%d" , &cas);
    while(cas--){
         scanf("%d" , &n);
         for(int i = 1 ; i <= n ; i++) 
             scanf("%d" , &num[i]);
         solve();
    }
    return 0;
}
