#include <iostream>
using namespace std;
int main(){
	int c;
	int max = 0;
	cin >> c;
	for(int i= 0 ;i<c;i++){
		int p[10];
		string d[10];
		for(int j= 0 ;j < 10;j++){
			cin>>d[j]>>p[j];
			if(p[j] >= max){
				max = p[j];
			}
		}
		
		cout << "Case #"<<i+1<<":"<<endl;
		for(int j = 0 ;j<10;j++){
			if(p[j] == max){
				cout <<d[j]<<endl;
			}
		}
			max = 0;
	}
	
	return 0;
	
}