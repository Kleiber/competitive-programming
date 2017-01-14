#include<bits/stdc++.h>
#define MAX 10005
using namespace std;
vector<long double> V;
int frequence[MAX];

double findArea(long double mid, int n){
	long double area = n * mid;
	int ind = upper_bound(V.begin(), V.end(), mid) - V.begin();
	for(int i = 0; i < ind; i++) area -= (mid - V[i])*frequence[(int)V[i]];
	return area;
}

double binarySearch(long double lo, long double hi, long double area, int n){
	long double num, mid, total;
	
	while(lo <= hi){	
		mid = lo + (hi - lo)/2.0;
		total = findArea(mid, n);
		if(total == area) return mid;
		else{
			if(total < area) lo  = mid;
			else hi = mid;
		}
	}
	
	return -1;
}

int main(){
	
	int n;
	long double area, total, num, lo, hi, ans;
	while(cin>>n>>area && n && area){
		
		V.clear();
		memset(frequence, 0, sizeof(frequence));
		
		lo = hi = total = 0.0;
		
		for(int i = 0; i < n; i++){
			cin>>num;
			
			if(frequence[(int)num] == 0) V.push_back(num);
			frequence[(int)num]++;
			
			total += num;
			if(num > hi) hi = num;
		}
		
		sort(V.begin(), V.end());
		
		if(total == area) cout<<":D"<<endl;
		else{
			if(total < area) cout<<"-.-"<<endl;
			else{
				ans = binarySearch(lo, hi, total - area, n);
				
				if(ans == -1) cout<<"-.-"<<endl;
				else printf("%.4Lf\n", ans);
			}
		}
	}
	
	return 0;
}