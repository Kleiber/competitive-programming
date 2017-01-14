#include<iostream>
using namespace std;
int T;
unsigned long long int N;
string L, ans;

int pos(int n){
	int ans  = (n == 0)? L.size() - 1 : n - 1;
	return ans;
}
int main(){
	cin>>T;
	for(int i = 1; i <= T; i++){
		cin>>L>>N;
		unsigned long long int acum = 1,aux,d = 0,r = 0;
		ans = "";
		
		aux = N % L.size();
		ans = L[pos(aux)] + ans;
		acum *= L.size();
		
		int k = 0;
		while(N > acum){
			cout<<N<<" "<<d<<" "<<r<<" "<<endl;
			N -= acum;
			d = N / acum;
			r = N % acum;
			if(r != 0) d++;
			aux = d % L.size();
			ans = L[pos(aux)] + ans;
			acum *= L.size();
			k++;
		}
		
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
   
   
   
