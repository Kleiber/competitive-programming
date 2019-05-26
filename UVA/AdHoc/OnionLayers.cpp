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
using namespace std;
struct Punto{
	double x, y;
	Punto() {}
	Punto(double X, double Y){x =X;y=Y;}
};
Punto pivot;

double dist(Punto a,Punto b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
double distancia(Punto a,Punto b){
	return sqrt(dist(a, b));
}

double cruce(Punto a,Punto b,Punto c){
	double d = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if(fabs(d) < 1e-9) return 0.0;
	return d;
}

bool Angulo(Punto u, Punto v){
	double t = cruce(pivot, v, u);
	if(t < 0.0) return true;
	if(t == 0){
		return (dist(pivot, u) < dist(pivot, v));
	}
	return false;
}

vector<Punto> graham(vector<Punto> p){
	for(int i = 1; i < p.size(); ++i){
		if(p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x ))
			swap(p[0], p[i]);
	}
	pivot = p[0];
	sort(p.begin(), p.end(), Angulo);
	vector<Punto> ans(p.begin(), p.begin()+3);
	for(int i = 3; i < p.size(); ++i){
		while(ans.size() >= 2 && cruce(ans[ans.size()-2], ans[ans.size()-1], p[i]) <= 0){
			ans.erase(ans.end() - 1);
		}
		ans.push_back(p[i]);
	}
	return ans;
}
vector<Punto> borrar(vector<Punto> p,vector<Punto> b){
	for( int i = 0; i < b.size() ; i++){
		for(int  j = 0; j < p.size(); j++){
			if(b[i].x == p[j].x && b[i].y == p[j].y){
				p.erase(p.begin() + j);
				break;
			}
		}
	}
	return p;
}
int main(){
	vector<Punto> v;
	vector<Punto>va;
    int n;
    double c1,c2;
    while(1){
		cin>>n;
		if(n==0)break;
		Punto p;
		for(int i = 0; i < n; i++){
			cin>>c1>>c2; 
			p.x=c1; p.y=c2;
			v.push_back(p);
        }
		
		int cont = 0;
		while(v.size() != 0){
			cont++;
			va=graham(v);			
			v = borrar(v,va);
		}
		v.clear();
		va.clear();
		if(cont % 2 == 0) cout<<"Do not take this onion to the lab!"<<endl;
		else cout<<"Take this onion to the lab!"<<endl;
    }
return 0;
}
