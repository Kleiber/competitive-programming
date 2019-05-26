#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define LLU long long unsigned int
#define eps 0.0004
using namespace std;
int main()
{
    double x1[11],x2[11],y1[11],y2[11],xin,yin;
    char c;
    int i = 0,N,cases = 0;
    bool found;
    while(cin>>c){
        if(c=='*') break;
        scanf("%lf%lf%lf%lf\n",&x1[i],&y1[i],&x2[i],&y2[i]);
        i++;
    }
    N = i;
    i = 0;
    while(1){
        cases++;
        cin>>xin>>yin;
        if(fabs(xin - 9999.9) <= eps && abs(yin - 9999.9) <= eps) break;
        
		found = false;
		
        for(i = 0; i < N; i++){
            if(xin > x1[i] && xin < x2[i] && yin < y1[i] && yin > y2[i]){
                found=true;
                cout<<"Point "<<cases<<" is contained in figure "<<i+1<<endl;
            }
        }
        if(!found) cout<<"Point "<<cases<<" is not contained in any figure\n";
    }
    return 0;
}