#include<iostream>
#include<map>
using namespace std;
int main(){
	map<char,string> M;
	M['1'] = "O-|O-OOO";
	M['2'] = "O-|OO-OO";
	M['3'] = "O-|OOO-O";
	M['4'] = "O-|OOOO-";
	M['5'] = "-O|-OOOO";
	M['6'] = "-O|O-OOO";
	M['7'] = "-O|OO-OO";
	M['8'] = "-O|OOO-O";
	M['9'] = "-O|OOOO-";
	M['0'] = "O-|-OOOO";
	
	string n;
	cin>>n;
	for(int i = n.size() - 1; i >= 0; i--) cout<<M[n[i]]<<endl;
	return 0;
}