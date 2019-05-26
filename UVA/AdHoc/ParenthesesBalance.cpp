#include<iostream>
#include<sstream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
#define db(a) cout << #a << " = " << a << endl;
using namespace std;
int main(){
    int t;
    scanf("%d\n", &t);
    string cadena;
    for(int i = 0; i < t; i++){
        stack<char> pila;
        getline(cin, cadena);
        if(cadena.size() == 0) {
            printf("Yes\n");
            continue;
        }
        int len = cadena.size();
        int k = 0;
        for(; k < len; k++){
            if(cadena[k] == '(' || cadena[k] == '[')
                pila.push(cadena[k]);
            else
                if(!pila.empty() && ((pila.top() == '[' && cadena[k] == ']' )||
                (pila.top() == '(' && cadena[k] == ')'))) pila.pop();
                else break;
        }
        if(pila.empty() && k == len) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}