#include<iostream>
using namespace std;
int main(){
    int t,n,c;
    string s;
	cin>>t;
	for(int j = 0; j < t; j++){
		cin>>n>>s;
		c = 0;
		for(int i = 0; i < n;){
			if(s[i] == '#') i++;
			else{
				c++;
				i += 3;
			}
		}
		cout<<"Case "<< j + 1<<": "<<c<<endl;
	}
    
    return 0;
}