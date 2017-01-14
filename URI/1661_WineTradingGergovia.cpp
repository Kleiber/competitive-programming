#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int n, num, ans;
	
    while (cin>>n && n){
		
        queue<pair<int, int> > P, N;
		
        for (int i = 0; i < n; i++){
			cin>> num;
			if(num > 0) P.push(make_pair(num, i));
			else N.push(make_pair(num, i));
        }

		ans = 0;
		
        while (P.size() > 0 && N.size() > 0){
			int ind1 = P.front().second;
			int ind2 = N.front().second;
            
			if(ind1 < ind2){
				int cant1 = P.front().first;
				P.pop();
				
                while (cant1 > 0){
					int cant2 = N.front().first;
					
					if(cant1 +  cant2 < 0){
						N.front().first += cant1;
						ans += (N.front().second - ind1) * cant1;
						cant1 = 0;
                    }else{
						cant1 += cant2;
						ans += (N.front().second - ind1) * -cant2;
						N.pop();
                    }
                }
            }else{
				int cant1 = N.front().first;
				N.pop();
				
                while (cant1 < 0){
					int cant2 = P.front().first;
					
					if(cant1 + cant2 > 0){
						P.front().first += cant1;
						ans += (P.front().second - ind2) * -cant1;
						cant1 = 0;
                    }else{
						cant1 += cant2;
						ans += (P.front().second - ind2) * cant2;
						P.pop();
                    }
                }
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}