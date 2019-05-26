#include<iostream>
using namespace std;
int main(){
	int n;
	string iman;
	char polo;
	int ans = 0;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>iman;
		if(i != 0){
			if(iman[0] == polo) ans++;
		}
		polo = iman[1];
	}
	
	cout<<ans + 1<<endl;
	return 0;
}