#include <iostream>
using namespace std;
int main(){
	int c,n ,m = 0,b,S=0,B=0 ;
	cin >> c;
	cout << "Lumberjacks:"<<endl;
	for (int i = 0; i < c; i++){
		cin >> n;
		m = n;
		for (int j = 0; j < 9; j++)
		{
			cin >> n;
			if(n > m)
				S++;
			else
				B++;
		}
		
		if(S == 9 || B == 9)
			cout << "Ordered"<<endl;
		else
			cout << "Unordered "<<endl;
	}
	return 0;
}