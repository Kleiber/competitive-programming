#include <iostream>
using namespace std;
int main (){
	int t, i, f;
	string s;
	char d;

	cin >> t;
	
	for (int k = 0; k < t; k++){
		cin >> s;
		d = s[0];
		f = 1;
		for(int i = 0; i < s.size(); i++){ 
			if (d == s[i+1]) f++;
			else{
				cout<<f<<d;
				f = 1;
				d = s[i+1];
			}
		}
		cout<<endl;
	}
	return 0;
}
