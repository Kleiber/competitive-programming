#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
using namespace std;
int arr[10010];

int main(){
    int n;    
    while(scanf("%d",&n),n){
        for(int i = 0;i<n;i++)  scanf("%d",&arr[i]);
        bool f = true;
        int inicio = 0;
        while(inicio < n && f){
            sort(arr,arr+n,greater<int>());
            
            if(arr[inicio] >= n - inicio){
                f = false;
                break;
            }
            
            for(int i=1;i<=arr[inicio];i++){
                arr[inicio + i]--;
                if(arr[inicio + i] < 0){
                    f = false;
                    break;
                }
            }
            inicio++;
        }
        if(f)    printf("Possible\n");
        else        printf("Not possible\n");
    }

    return 0;
}