#include<iostream>
#include<sstream>
using namespace std;

string toString(int n){
  stringstream in;
  in<<n;
  string s = in.str();
  return s;
}

int toInt(string s){
  stringstream in(s);
  int n;
  in>>n;
  return n;
}

int solve(string num){
  int len = num.size();
  if(len == toInt(num)) return 1;
  else return 1 + solve(toString(len));
}

int main(){
  string s;
  while(cin>>s && s != "END") cout<<solve(s)<<endl;
  return 0;
}