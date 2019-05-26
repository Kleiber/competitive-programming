#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main(){
	int cases;
	cin>>cases;
	for(int i = 1; i <= cases; i++){
		double d,v,u;
		cin>>d>>v>>u;
		
		cout<<"Case "<<i<<": ";
		if(u == 0 ||v == 0|| u <= v) cout<<"can't determine"<<endl;
		else{
			double f = d/sqrt(u*u - v*v);
			double s = d/u;
			
			double ans = f > s? f - s : s - f;
			printf("%.3f\n",ans);
		}
		
	}
	return 0;
}