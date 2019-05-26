#include<iostream>
#include<math.h>
using namespace std;
int main(){
	long long x,y;
	cin>>x>>y;
	long long x1 = 0,y1 = 0,x2 = 0,y2 = 0;
	if(x > 0  && y > 0) y1 = x2 = x + y;
	if(x < 0  && y < 0) x1 = y2 = x + y;
	if(x > 0  && y < 0) y1 = y - x, x2 = x - y;
	if(x < 0  && y > 0) x1 = x - y,  y2 = y - x;
	
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	return 0;
}