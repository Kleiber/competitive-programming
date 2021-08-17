#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define MAX 500005
int padre[MAX];
int numVertices[MAX];

int find(int x){
    if(padre[x] == x) return x;
    return padre[x] = find(padre[x]);
}
int join(int x,int y){
    int X = find(x);
	int Y = find(y);
	
    if(X != Y) padre[Y] = X;
    if(X != Y) numVertices[X] += numVertices[Y];
    return numVertices[Y] = numVertices[X];
}

int main(){
    int casos;
    cin>>casos;
	for(int i = 0; i < casos; i++){
		int n;
		while(cin>>n){
			map<string,int> M;
			int k = 0;
			for(int i = 0; i < n*2; i++){
				padre[i] = i;
				numVertices[i] = 1;
			}
			while(n--){
				string a,b;
				cin>>a>>b;
				if(M[a] == 0) M[a] = k++;
				if(M[b] == 0) M[b] = k++;
				cout<<join(M[a],M[b])<<endl;
			}
		}
	}
}