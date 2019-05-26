#include <iostream>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t --){
    int n, l, r;
    cin >> n >> l >> r;
    if(n / l == 0){
      cout << "No\n";
      continue;
    }
    long long mx = ((long long)n / l) * r;
    if(mx >= n)
      cout << "Yes\n";
    else
      cout << "No\n";
  }

  return 0;
}