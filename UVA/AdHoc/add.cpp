#include<cstdio>
using namespace std;
int main(){
 unsigned long int a,b;
 while (cin>>a>>b){
  if (a>b)
   cout<<a-b<<endl;
  else
   cout<<b-a<<endl;
 }
 return 0;
}