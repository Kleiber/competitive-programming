#include <iostream>
using namespace std;  

int main(){  
    int piles, stones, tmpStones;  
    while (cin>>piles && piles)  {  
        stones = 0;  
        for (int i = 0; i < piles; i++){  
            cin >> tmpStones;  
            stones ^= tmpStones;  
        }  
        cout<<(stones ? "Yes" : "No")<<endl;  
    }  
    return 0;  
}  