#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#define MAX 205
#define INF 2000000000
using namespace std;
int l1[105], r1[105];

int main(){
  int n;
  cin >> n;
  int l, r;
  cin >> l >> r;
  int ans = r - l;

  for(int i = 1; i < n; ++i)
    cin >> l1[i] >> r1[i];

  for(int i = l; i < r; ++i)
    for(int j = 1; j < n; ++j)
      if(l1[j] <= i && r1[j] >= i + 1){
        --ans;
        break;
      }

  cout << ans;

  return 0;
}