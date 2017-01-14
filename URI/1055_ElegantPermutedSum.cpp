#include <bits/stdc++.h>
#define MAX 55
using namespace std;
  
int num[MAX];
  
int main(){
    int n , q, casos = 1;
    cin>>n;
     
    while(n--){
        vector<int> v1,v2;
         
        cin>>q;
        int med = (q % 2 == 0)? floor(q/2) - 1:floor(q/2) + 1;
        for(int i = 0; i < q; i++) cin>>num[i];
        sort(num, num + q);
          
          
        if(q % 2 == 0){
            int j = 1;
            for(int i = med; i >= 0; i--){
                v1.push_back(num[i]);
                v1.push_back(num[q - j]);
                j++;
            }
        }else{
            v1.push_back(num[0]);
            v1.push_back(num[q - 1]);
            v1.push_back(num[1]);
              
            int inicio = 2;
            int fin = q - 2;
            bool f = 1;
                            
            while(fin >= inicio){
                if(f){
                    v1.insert(v1.begin(), num[fin--]);
                    v1.insert(v1.begin(), num[inicio++]);
                    f = 0;
                }else{
                    v1.push_back(num[fin--]);
                    v1.push_back(num[inicio++]);
                    f = 1;
                }
            }
          
            v2.push_back(num[q - 1]);
            v2.push_back(num[0]);
            v2.push_back(num[q - 2]);
  
            inicio = 1;
            fin = q - 3;
            f = 1;
  
            while(fin >= inicio){
                if(f){                   
                    v2.insert(v2.begin(),num[inicio++]);
                    v2.insert(v2.begin(),num[fin--]);
                    f = 0;
                }else{
                    v2.push_back(num[inicio++]);
                    v2.push_back(num[fin--]);
                    f = 1;
                }
            }
        }
         
        int suma1 = 0;
        int suma2 = 0;
        for(int i = 1; i < q; i++){
            suma1 += abs(v1[i] - v1[i - 1]);
            if(q % 2 != 0) suma2 += abs(v2[i] - v2[i-1]);
              
        }
  
        cout<<"Case "<<casos<<": "<<max(suma1,suma2)<<endl;
        casos++;
    }
    return 0; 
}