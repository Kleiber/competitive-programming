#include<iostream>
#include<bitset>
#include<algorithm>
using namespace std;
int main() {
        int a,b;
        while(cin>>a>>b){
                bitset<32> ans = a ^ b;
                //string mystring;
                //mystring=ans.to_string<char,char_traits<char>,allocator<char> >();
                //cout << "mystring: " << mystring << endl;
                cout<<ans.to_ulong()<<endl;
        }
        
}
