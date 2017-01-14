#include<bits/stdc++.h>
using namespace std;
int M[5][5];
int A[10];

void back(int nodo, int lon){
    A[nodo] = lon;

    if (lon == 8) {
        for (int i = 0; i < 9; i++) cout<<A[i] + 1;
		cout<<endl;
        return;
    }

	for(int i = 0; i < 5; i++){
		if(M[nodo][i]){
			M[nodo][i] = M[i][nodo] = 0;
			back(i, lon + 1);
			M[nodo][i] = M[i][nodo] = 1;
		}
	}

}

int main(){
	memset(M, 0, sizeof(M));

    M[0][1] = M[0][2] = M[0][4] = 1;
    M[1][0] = M[1][2] = M[1][4] = 1;
    M[2][0] = M[2][1] = M[2][3] = M[2][4] = 1;
    M[3][2] = M[3][4] = 1;
    M[4][0] = M[4][1] = M[4][2] = M[4][3] = 1;

    back(0, 0);
    return 0;
}