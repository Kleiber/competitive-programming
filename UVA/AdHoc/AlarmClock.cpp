#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;int main(){
	int H1,M1,H2,M2,ans;
	cin>>H1>>M1>>H2>>M2;
	while(H1 || M1 || H2 || M2){
		int min;
		if((H1 == H2)&&(M1 == M2)) min = 0;
		else{ 
			if(H1 < H2)
				min=abs((H1*60 +  M1) - (H2*60 + M2));
			else{ 
				if((H1 == H2) && (M1 > M2))
					min=abs(abs((H1*60 + M1) - (H2*60 + M2)) - 1440);
				else{
					if(H1 > H2)
						min=abs(abs((H1*60 + M1) - (H2*60 + M2))- 1440);
					else
						min=abs((H1*60 + M1) - (H2*60 + M2));
				}	
			}
		}
		cout<<min<<endl;
		cin>>H1>>M1>>H2>>M2;
	}
	return 0;
}