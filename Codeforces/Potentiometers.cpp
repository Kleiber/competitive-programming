#include<iostream>
#include<cstring>
#define MAX 200005
using namespace std;
struct nodo{
	int sum;
	nodo(){}
	nodo(int _sum){sum = _sum;}
};

nodo T[4*MAX]; int a[MAX];

void init(int b, int e, int node){
	if(b == e) T[node].sum = a[b];
	else{
		int mid = (b+e)/2, le = 2*node +1, ri = 2*node + 2;
		init(b, mid, le);
		init(mid + 1, e, ri);
		T[node].sum = T[le].sum + T[ri].sum;
	}
}

nodo query(int b, int e, int node, int i, int j){
	if(i <= b && e <= j) return T[node];
	
	int mid = (b+e)/2, le = 2*node +1, ri = 2*node + 2;
	
	if(j <= mid) return query(b, mid, le, i, j);
	else{
		if(mid < i) return query(mid + 1, e, ri, i, j);
		else{
			nodo ret1 = query(b, mid, le, i, j);
			nodo ret2 = query(mid + 1, e, ri, i, j);
			
			nodo ret;
			ret.sum = ret1.sum + ret2.sum;
			return ret;
		}
	}
}

void update(int b, int e, int node, int i, int v){
	if(i < b || i > e) return;
	
	if(b == e) T[node].sum = a[i] = v;
	else{
		int mid = (b+e)/2, le = 2*node +1, ri = 2*node + 2;
		
		update(b, mid, le, i, v);
		update(mid + 1, e, ri, i, v);
		
		T[node].sum = T[le].sum + T[ri].sum;
	}
}

int main(){
	int n, cont = 1;
	
	while(cin>>n && n){
		if(cont > 1) cout<<endl;
		
		cout<<"Case "<<cont<<":"<<endl;
		memset(a,0,sizeof(a));
		
		for(int i = 0; i < n; i++) cin>>a[i];
		
		init(0, n-1, 0);
		
		string s;
		int a,b;
		while(cin>>s && s != "END"){
			cin>>a>>b;
			if(s == "M") cout<<query(0, n - 1, 0, a - 1, b - 1).sum<<endl;
			if(s == "S") update(0, n - 1, 0, a - 1, b);
		}
		cont++;
	}
	return 0;
}