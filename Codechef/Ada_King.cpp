#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
#define MAX 8

int dr[MAX] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[MAX] = {0, 1, 1, 1, 0, -1, -1, -1};
int visited[MAX][MAX];

bool isValid(int r, int c) {
    return r >= 0 && r < MAX && c >= 0 && c < MAX;
}

int main() {
    int T;
    cin>>T;

    for(int i = 0; i < T; i++) {
        if (i > 0) cout<<endl;
        
        int N;
        cin>>N;

        memset(visited, 0, sizeof(visited));
        
        int r0 = 2;
        int c0 = 3;

        queue< pair<int,int> > Q;
        Q.push(make_pair(r0, c0));
        visited[r0][c0] = 1;

        while(!Q.empty()) {
            int r = Q.front().first;
            int c = Q.front().second;         
            Q.pop();

            if (N > 0) {
                for(int i = 0; i < MAX; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(!visited[nr][nc] && isValid(nr, nc)){
                        Q.push(make_pair(nr, nc));
                        visited[nr][nc] = 1;
                    }
                }
            } else visited[r][c] = 2;

            N--;
        }

        for(int i = 0; i < MAX; i++) {
            for(int j = 0; j < MAX; j++) {
                if (i == r0 && j == c0) cout<<"O";
                else {
                    if(visited[i][j] == 2) cout<<"X";
                    else cout<<".";
                }
            }cout<<endl;
        }
    }

    return 0;
}