#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
	vector<long long> v;
	long long T,contador = 1;
	cin>>T;
	while(T--){
		long long n,k,a,b,c,r,e;
		map<long long,long long> M;
		cin>>n>>k;
		cin>>a>>b>>c>>r;
		v.push_back(a);
		M[a]++;
		for(long long i = 1; i < k; i++){
			e = (b * v[i - 1] + c) % r;
			v.push_back(e);
			M[e]++;
		}
		

		long long point = 0;
		for(long long i = k; i < n; i++){
			long long menor = 0;
			bool f= false;
			while(!f){
				if(M[menor] > 0) menor++;
				else{
					v.push_back(menor);
					M[menor]++;
					f = true;
				}
				//cout<<".."<<endl;
			}
			e = v[point]; 
			M[e] --;
			point++;
		}
		
		cout<<"Case #"<<contador<<": "<<v[n-1]<<endl;
		contador++;
		v.clear();
	}
	return 0;
}
