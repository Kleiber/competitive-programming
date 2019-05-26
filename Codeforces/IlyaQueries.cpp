#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	int x,y,z,contador=0;
	vector<int> v;
	v.push_back(0);
	string a;
	cin>>a>>x;
	for(int i=0; i<a.size()-1; i++){
		if(a[i]==a[i+1])
		{
			contador++;
			v.push_back(contador);
		}
		else v.push_back(contador);
	}
	while(x--)
	{
		cin>>y>>z;
		cout<<v[z-1]-v[y-1]<<endl;
	}
	return 0;
}
/*
#include<iostream>
#include<string>
using namespace std;
int mayor(int x, int y){
	if(x > y) return x;
	else return y;
}

int main(){
	int P[100005];
	int M[100005];
	string s;
	cin>>s;
	for(int i = 0; i < 1000005; i++){
		P[i] = 0; M[i] = 0;
	}
	
	if(s[0] == '.') P[1] = 1;
	else M[1] = 1;
	
	for(int i = 1; i < s.size(); i++){
		if(s[i] == '.') {
			P[i + 1] = P[i] + 1;
			M[i + 1] = M[i];
		}
		else{
			M[i + 1] = M[i] + 1;
			P[i + 1] = P[i];
		}
	}
	
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		int x,y;
		cin>>x>>y;
		int a = P[y] - P[x - 1];
		int b = M[y] - M[x - 1];
		cout<<mayor(a,b) - 1<<endl;
	}
}
*/
