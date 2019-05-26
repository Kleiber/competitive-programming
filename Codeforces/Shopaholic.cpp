#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool orden(int a,int b)
{
    if(a > b ) return true;
    else return false;
}
int main(){
	int c,n,e;
	cin>>c;
	while(c--){
		vector<int> V;
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>e;
			V.push_back(e);
		}
		
		sort(V.begin(),V.end(),orden);
		
		int s = 0;
		while(V.size() != 0){
			if(V.size()/3 > 0){
				for(int i = 0; i < 2; i++)
					V.erase(V.begin());
				
				s+=V[0];
				V.erase(V.begin());
			}else{
				V.erase(V.begin());
			}
		}
		
		cout<<s<<endl;
	}
	return 0;
}