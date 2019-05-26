#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll ans,t,x,y,m;
int main()
{
    cin>>x>>y>>m;
    if(x>=m||y>=m){cout<<0;return 0;}
    if(x<=0&&y<=0){cout<<-1;return 0;}
    if(x>y)swap(x,y);
    if(x+y<0)ans-=x/y,x+=y*ans;
    while(x<m&&y<m)
        ans++,t=x+y,x=max(x,y),y=t;
    cout<<ans<<endl;
}
