/*
ID: edison11
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main (){
	ofstream cout ("milk2.out");
    ifstream cin ("milk2.in");
	
    int n;
    cin >> n;
    int a[2][5005];
	
    for(int i = 0; i < n; i++ ){
        cin>>a[0][i];
        cin>>a[1][i];
    }
 
    for(int i = 0; i < n; i++ ){
        for(int j = i + 1; j < n; j++){
            if(a[0][i] > a[0][j]){
                int temp = a[0][i];
                a[0][i] = a[0][j];
                a[0][j] = temp;
 
                temp = a[1][i];
                a[1][i] = a[1][j];
                a[1][j] = temp;
            }
        }
    }
 
    int ini = a[0][0];
    int fin = a[1][0];
    int ans1 = fin - ini;
    int ans2 = 0;
 
    for(int i = 1; i < n; i++){
        if(fin < a[1][i] ){
			if(a[0][i] <= fin)
                fin = a[1][i];
            else{
                if(fin - ini > ans1)
                    ans1 = fin - ini;
                 
                if(a[0][i] - fin > ans2)
                    ans2 = a[0][i] - fin;
                 
                ini = a[0][i];
                fin = a[1][i];
            }
        }
    }
	
	cout<<ans1<<" "<<ans2<<endl;
 
    return 0;
 
}