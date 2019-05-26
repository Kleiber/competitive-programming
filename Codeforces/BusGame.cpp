#include<iostream>
using namespace std;
int main(){
	int x,y;
	bool c = 1;
	cin>>x>>y;
	while(1){
		if(c){
			if(x > 1 && y > 1) x -= 2, y -= 2;
			else{
				if(x > 0 && y > 11) x -= 1, y -= 12;
				else{
					if(y > 21) y -= 22;
					else break;
				}
			}
			c = 0;
		}else{
			if(y > 21) y -= 22;
			else{
				if(y > 11 && x > 0) y -= 12, x -= 1;
				else {
					if(y > 1 && x > 1) y -= 2, x -= 2;
					else break;
				}
			}
			c = 1;
		}
	}
	if(c) cout<<"Hanako"<<endl;
	else cout<<"Ciel"<<endl;
	return 0;
}