#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<sstream>
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define INF 100000000
#define mod abs
#define pf printf
#define sf scanf
 
using namespace std;
#define MAXX 100005
 
int height[MAXX];
int n; 

int main(){
    long long left[MAXX], right[MAXX];
    long long result;
    while(true){
        getint(n);
        if(n == 0) break;
 
        height[0] = -1;
 
        for(int i=1; i<=n; i++)
        {
            getint(height[i]);
        }
 
        height[n+1] = -1;
 
        //{
            stack<int>sk;
            sk.push(0);
            for(int i=1; i<=n; i++)
            {
                while( height[sk.top()] >= height[i] )
                {
                    sk.pop();
                }
                left[i] = i - sk.top();
                sk.push(i);
 
            }
        //}
 
        //{
 
 
            stack<int>st;
            st.push(n+1);
 
            for(int i = n; i>0; i--)
            {
                while(height[st.top()] >= height[i] )
                {
                    st.pop();
                }
                right[i] = st.top() - i;
                st.push(i);
 
            }
        //}
 
        result = -INF;
 
        for(int i=1; i<=n; i++)
        {
            result = max(result, (left[i] + right[i]-1) * height[i]) ;
        }
        cout<<result<<endl;
    }
 

}