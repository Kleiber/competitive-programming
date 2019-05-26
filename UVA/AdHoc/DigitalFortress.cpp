#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n;
	getline(cin,s);
	while(n--){
		getline(cin,s);
		double R = sqrt(s.size());
		int r = (int)R;
		if(r*r == s.size()){
			string s1 = "";
			for(int i = 0; i < R; i++){
				int c = i;
				for(int j = 0; j < R; j++){
					s1 += s[c];
					c += R;
				}
			}
			cout<<s1<<endl;
		}else
			cout<<"INVALID"<<endl;
	}
	return 0;
}