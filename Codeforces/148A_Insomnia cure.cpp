#include <iostream>
using namespace std;
int main() 
{
  int*A = NULL;
  int damage = 0,k,l,m,n,d;
  cin>>k>>l>>m>>n>>d;
  A = new int[d];
  int B[4]={k,l,m,n};
  
  for(int i=0;i<d;i++){
    A[i] = 1;
  }
  
  for(int i=0;i<4;i++){
    for(int j=1;j<=d;j++){
      if(j%B[i]==0 && A[j - 1]==1){
        damage++;
        A[j - 1] = 0;
      }
    }
  }
  cout<<damage<<endl;
    return 0;
}