#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<char> pila;
	string s;
	cin>>s;
    for(int i = 0; i < s.size(); i++) {
        if(pila.empty()) pila.push(s[i]);
        else {
            if(s[i] == pila.top()) pila.pop();
            else pila.push(s[i]);
            
        }
    }
    if(pila.empty()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
