#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#define MAX 100005
using namespace std;
int main(){
	int n,cont = 0;
	int ocurr[MAX];
	int RA[MAX];
	int Pos[MAX];
	map<int,bool> PA;
	
	memset(ocurr,0,sizeof(ocurr));
	memset(RA,0,sizeof(RA));
	memset(Pos,-1,sizeof(Pos));
	
	cin>>n;
	for(int i = 0; i < n; i++){
		int e;
		cin>>e;
		//cout<<e<<" "<<ocurr[e]<<endl;
		if(ocurr[e] == 0){
			RA[e] = 0;
			PA[e] = 1;
			Pos[e] = i;
			ocurr[e]++;
			cont++;
		}else{
			if(PA[e]){
				if(RA[e] == 0){
					RA[e] = i - Pos[e];
					PA[e] = 1;
					Pos[e] = i;
				}else{
					if(i - Pos[e] == RA[e])	Pos[e] = i;
					else{
						PA[e] = 0;
						cont--;
					}
				}
			}
		}
		
		//cout<<e<<" "<<PA[e]<<" "<<RA[e]<<" "<<Pos[e]<<endl;
	}
	
	cout<<cont<<endl;
	map <int, bool> :: iterator it;
	for(it = PA.begin(); it != PA.end(); it++){
		int x = it->first;
		bool flag = it->second;
		
		if(flag) cout<<x<<" "<<RA[x]<<endl;
	}	

	return 0;
}