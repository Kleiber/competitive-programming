#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>                              
using namespace std;
#define INF 1000000000
#define MAX 1000000
int nn = 1;

struct tree {
	int add, mn;
	tree() {add = mn = INF;}
}t[2 * MAX];

void push (int v) {
	if (t[v].add != INF) {
		t[v].mn = min(t[v].mn, t[v].add);
		t[v + v].add = min(t[v].add, t[v + v].add);
		t[v + v + 1].add = min(t[v].add, t[v + v + 1].add);
		t[v].add = INF;
	}
}

void update(int l, int r, int x, int v = 1, int tl = 1, int tr = nn) {
	push(v);
	if (l > tr || tl > r || l > r) return;
	if (l <= tl && tr <= r) {
		t[v].add = min(t[v].add, x);
		push(v);
		return;
	}
	int mid = (tl + tr) / 2;
	update(l, r, x, v + v, tl, mid);
	update(l, r, x, v + v + 1, mid + 1, tr);
	t[v].mn = min(t[v + v].mn, t[v + v + 1].mn);
}

int get(int l, int r, int v = 1, int tl = 1, int tr = nn) {
	push(v);
	if (l > tr || tl > r || l > r) return INF;
	if (l <= tl && tr <= r) return t[v].mn;
	int mid = (tl + tr) / 2;
	return min(get(l, r, v + v, tl, mid), get(l, r, v + v + 1, mid + 1, tr));
}

int n, m, l[MAX], r[MAX], w[MAX];

int main (){
	cin>>n>>m;
	
	while (nn < n) nn += nn;

	for (int i = 1; i <= m; i++ ) {
		cin>>l[i]>>r[i]>>w[i];
		update(l[i], w[i] - 1, i);
		update(w[i] + 1, r[i], i);
	}

	for (int i = 1; i <= n; i ++ ){
		int ans = get(i, i);
		
		if (ans == INF) ans = 0;
		else ans = w[ans];
		
		if(i == n) cout<<ans<<endl;
		else cout<<ans<<" ";
	}

	return 0;
}