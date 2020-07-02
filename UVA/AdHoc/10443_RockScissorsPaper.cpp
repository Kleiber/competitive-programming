#include<iostream>
using namespace std;
#define MAX 1000

int T, R, C, N;
string M[MAX], A[MAX];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool valid(int r, int c){
    return c >= 0 && c < C && r >= 0 && r < R;
}

void evaluate(int r, int c, int nr, int nc){
    if(M[r][c] == 'R'){
        if(M[nr][nc] == 'P') A[r][c] = 'P';
        else A[nr][nc] = 'R';
        return;
    }

    if(M[r][c] == 'P'){
        if(M[nr][nc] == 'R') A[nr][nc] = 'P';
        else A[r][c] = 'S';
        return;
    }

    if(M[r][c] == 'S'){
        if(M[nr][nc] == 'R') A[r][c] = 'R';
        else A[nr][nc] = 'S';
        return;
    }
}

int main(){
    int T, cases;
    cin>>T;

    cases = 0;
    while(T--){
        if(cases++) cout<<endl;

        cin>>R>>C>>N;
        for(int i = 0; i < R; i++){
            cin>>M[i];
            A[i] = M[i];
        }
        
        while(N--){

            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){

                    for(int k = 0; k < 4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(valid(nr, nc) && M[i][j] != M[nr][nc]){
                            evaluate(i, j, nr, nc);
                        }
                    }

                }
            }

            for(int i = 0; i < R; i++) M[i] = A[i];
        }

        for(int i = 0; i < R; i++) cout<<M[i]<<endl;
    }
    return 0;
}