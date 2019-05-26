#include<iostream>
#include<iostream>
#include<string>
#include<math.h>
#include<sstream>
using namespace std;
int main(){
	string s,s1;
	while(cin>>s && s != "0"){
		s1 = s;
		int sum = 0;
		int n = 1;
		for(int i = 0; i < s.size(); i++) sum += s[i] - '0';

		if(sum % 9 == 0){
			while(sum >= 10){
				stringstream out;
				out<<sum;
				s = out.str();
				sum = 0;
				for(int i = 0; i < s.size(); i++) sum += s[i] - '0';
				n++;
			}
			
			cout<<s1<<" is a multiple of 9 and has 9-degree "<<n<<"."<<endl;
		}
		else
			cout<<s1<<" is not a multiple of 9."<<endl;
	}
	return 0;
}