#include <stdio.h>
#include <vector>
using namespace std;

struct vect
{
	int st, dr;
};

int n;
vector <int> v[300005];
vect poz[600005];
int aib1[600005], aib2[600005], st[600005], h[600005];

const int mod = 1000000007;

void dfs (int nod)
{
	st[++st[0]] = nod;
	poz[nod].st = st[0];
	for (vector <int> :: iterator it = v[nod].begin(); it != v[nod].end(); it ++)
	{
		h[*it] = h[nod] + 1;
		dfs (*it);
	}
	st[++st[0]] = nod;
	poz[nod].dr = st[0];
}

void update1 (int poz, int val)
{
	while (poz <= st[0])
	{
		aib1[poz] = (aib1[poz] + val) % mod;
		poz += poz & -poz;
	}
}

void update2 (int poz, int val)
{
	while (poz <= st[0])
	{
		aib2[poz] = (aib2[poz] + val) % mod;
		poz += poz & -poz;
	}
}

int query1 (int poz)
{
	int val = 0;
	while (poz >= 1)
	{
		val = (val + aib1[poz]) % mod;
		poz -= poz & -poz;
	}
	return val;
}

int query2 (int poz)
{
	int val = 0;
	while (poz >= 1)
	{
		val = (val + aib2[poz]) % mod;
		poz -= poz & -poz;
	}
	return val;
}

int main (){
	scanf ("%d", &n);
	
	int i, x, y, z, t, tip;
	
	for (i = 2; i <= n; i ++)
	{
		scanf ("%d", &x);
		v[x].push_back (i);
	}
	
	dfs (1);
	
	scanf ("%d", &t);
	while (t --)
	{
		scanf ("%d", &tip);
		if (tip == 1)
		{
			scanf ("%d %d %d", &x, &y, &z);
			update1 (poz[x].st, ((long long)y + (long long)h[x] * z) % mod);
			update1 (poz[x].dr, (((long long)-y - (long long)h[x] * z) % mod + mod) % mod);
			update2 (poz[x].st, z % mod);
			update2 (poz[x].dr, (-z % mod + mod) % mod);
		}
		else
		{
			scanf ("%d", &x);
			int sol = (query1 (poz[x].st) - (long long)query2 (poz[x].st) * h[x] + mod) % mod;
			printf ("%d\n", (sol + mod) % mod);
		}
	}
	return 0;
}