#include<iostream>
#include<string>
using namespace std;
bool comp1(string a, string b){
	bool f = 1;
	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[i]){
			if(a[i] > b[i]){
				f = 1;
				break;
			}
			else{
				f = 0;
				break;
			}
		}
	}
	return f;
}
bool comp(string a, string b, bool p, bool s){
	if(p && s){
		if(a.size() == b.size()){
			return comp1(a,b);
		}
		else{
			if(a.size() > b.size()) return 1;
			else return 0;
		}
	}else{
		if(p && !s) return 1;
		else{
			if(!p && s) return 0;
			else{
				if(a.size() == b.size()) return comp1(b,a);
				else{
					if(a.size() > b.size()) return 0;
					else return 1;
				}
			}
		}
	}
}
int main(){
	bool p = 1;
	string num;
	cin>>num;
	
	if(num[0] == '-'){
		p = 0;
		num = num.substr(1);
	}
	
	if(comp(num,"128",p,0) && comp("127",num,1,p))
		cout<<"byte"<<endl;
	else{
		if(comp(num,"32768",p,0) && comp("32767",num,1,p))
			cout<<"short"<<endl;
		else{
			if(comp(num,"2147483648",p,0) && comp("2147483647",num,1,p))
				cout<<"int"<<endl;
			else{
				if(comp(num,"9223372036854775808",p,0) && comp("9223372036854775807",num,1,p))
					cout<<"long"<<endl;
				else cout<<"BigInteger"<<endl;
			}
		}
	}
	return 0;
}
