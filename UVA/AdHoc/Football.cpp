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
#include<string.h>
using namespace std;
struct Team{
	string nombre;
	int pts,pj,pg,pe,pp,dg,gf,gc;
} ;
int main() {
	map<string ,Team> M;
	int N,T,G, M1,M2;
	string Torneo,Equipo, E1,E2;
	cin>>N;
	for(int i = 0; i< N;i++)
	{
		getline(cin,Torneo);
		getline(cin,Torneo);
		cout<<Torneo<<endl;
		cin>>T;
		getline(cin,Equipo);
		for(int j =0; j< T;j++) { 			
			getline(cin,Equipo);
			cout<<Equipo<<endl;
			M[Equipo] = Team();
		}
		cin>>G;
		for(int j =0; j< G;j++) { 
			getline(cin,E1);
			//scanf("%s*s%d*s%d*s%s",&E1,&M1,&E2,&M2);
			cout<<E1<<endl;
			
		}
		
	}
	return 0;
}
