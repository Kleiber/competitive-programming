#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>  
#include <cstdlib>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;
int R, C,casos;
bool visited[50][50];
 
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

vector <string> M;

bool orden(pair <char, int> p1, pair <char, int> p2)
{
    if(p1.second != p2.second) return p1.second > p2.second;
    else return p1.first < p2.first;
}

bool valid(int r, int c)
{
    return r >= 0 && r < R && c >= 0 && c < C;
}
 
int dfs(int r, int c)
{
    visited[r][c] = 1;
    int cnt = 1;
    for(int k=0; k<4; k++)
    {
        int nr = r + dr[k];
        int nc = c + dc[k];
         
        if(valid(nr, nc) && M[r][c] == M[nr][nc] && !visited[nr][nc])
            cnt += dfs(nr, nc);
    }
    return cnt;
}
 
int main()
{
	cin>>casos;
	for(int n = 0; n<casos;n++){
		cin>>R>>C;

        M = vector <string> (R);
        for(int i=0; i<R; i++)
            cin>>M[i];
         
        memset(visited, 0, sizeof(visited));
         
        vector < pair <char, int> > V;
		map<char,int>S;
		map<char,int>::iterator it;
         
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                if(!visited[i][j])
                {
                    V.push_back(make_pair(M[i][j], dfs(i, j)));
                }
            }
        }
		
        for(int i=0; i<V.size(); i++)
			S[V[i].first]++;
		
		V.clear();
		int j = 0;
		for(it=S.begin();it!=S.end();it++){
			V.push_back(make_pair((*it).first,(*it).second));
			j++;
		}			
			
		sort(V.begin(), V.end(), orden);
		
		cout<<"World #"<<n+1<<endl;
		for(int i=0; i<V.size(); i++)
            cout<<V[i].first<<": "<<V[i].second<<endl;
		
		
    }
    return 0;
}