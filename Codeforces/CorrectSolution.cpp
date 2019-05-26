#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	string num,ans;
	cin>>num;
	cin>>ans;
	
	sort(num.begin(),num.end());
	
	if(num[0] == '0'){
		string aux = "";
		bool f = 0;
		for(int i = 0; i < num.size(); i++){
			if(num[i] != '0' && !f){
				aux = num[i] + aux;
				f = 1;
			}else aux += num[i];
		}
		num = aux;
	}
	
	if(num == ans) cout<<"OK"<<endl;
	else cout<<"WRONG_ANSWER"<<endl;
	
	return 0;
}