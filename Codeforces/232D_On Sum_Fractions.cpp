#include <iostream>
#include <cmath>

using namespace std;

int prim(int x){
  if(x == 2)
    return 1;
  if(x % 2 == 0)
    return 0;
  int lim = sqrt(x);
  for(int i = 3; i <= lim; i += 2)
    if(x % i == 0)
      return 0;
  return 1;
}

long long cmmdc(long long x, long long y){
  long long z;
  while(y){
    z = x;
    x = y;
    y = z % y;
  }
  return x;
}

int main(){
  int t;
  cin >> t;
  while(t --){
    int n;
    cin >> n;
    int u = n + 1;
    int v = n;
	
    while(!prim(v)) --v;
    while(!prim(u)) ++u;
	
    long long t1 = ((long long)u - 2) * v - ((long long)u - n - 1) * 2;
    long long t2 = (long long)2 * u * v;
    long long gcd = cmmdc(t1, t2);
    cout << t1 / gcd << "/" << t2 / gcd << "\n";
  }

  return 0;
}