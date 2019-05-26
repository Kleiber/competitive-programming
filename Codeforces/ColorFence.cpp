#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	vector<int> v;
	int litros,aux,indice,cont=1;
	int n,menor=100001;
	string s="";
	cin>>litros;
	for(int i=0; i<9; i++){
		cin>>n;
		if(n<=menor){
			menor=n;
			indice=cont;
		}
		v.push_back(n);
		cont++;
	}
	int mod,aux2,indice2;
	bool flag=false;
	if(menor>litros) cout<<-1<<endl;
	else{
		if(menor==litros) cout<<indice<<endl;
		else{
			if(litros%menor==0){
				for(int i=0; i<litros/menor; i++)
					s+=(char)(indice+48);
				cout<<s<<endl;
			}
			else{
				aux2=litros/menor;
				mod=litros%menor;
				while(mod!=0){
					for(int i=indice; i<9; i++){
						if(menor+mod>=v[i]){
							indice2=i;
							flag=true;
						}
					}
					if(flag)
					{
						s+=(char)((indice2+1)+48);
						aux2--;
					}
					else break;
					
					mod=mod-(v[indice2]-menor);
					flag=false;
				}
				for(int i=0; i<aux2; i++)
					s+=(char)(indice+48);
				cout<<s<<endl;
			}
		}
	}
	return 0;
}
