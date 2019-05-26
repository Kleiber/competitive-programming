#include<iostream>
using namespace std;
int main(){
	int n,e;
	int a = 0, b = 0, sum = 0;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>e;
		if(e == 5){
			a++;
			sum += 5;
		}
		else b++;
	}
	
	//cout<<a<<" "<<b<<" "<<sum<<endl;
	if(b > 0){
		if(a > 0){
			bool f = 0;
			int x = 0;
			while(sum > 0){
				
				if(sum % 9 == 0){
					f = 1;
					x = sum/5;
					break;
				}else sum -= 5;
			}
			
			//cout<<f<<" "<<x<<" "<<sum<<endl;
			if(f){
				string s = "";
				for(int i = 0; i < x; i++) s+='5';
				for(int j = 0; j < b; j++) s+='0';
				cout<<s<<endl;
			}else cout<<0<<endl;
		}
		else cout<<0<<endl;
	}else cout<<-1<<endl;
}