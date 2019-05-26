#include<iostream>
#include<algorithm>
using namespace std;
int n,q,e;
int main() {
	cin>>n;
    int A[n];
	
    for(int i = 0; i < n; i++) cin>>A[i];
	
	cin>>q;
	
    for(int i = 0; i < q; i++) {
        cin>>e;
		//-- lb (menor valor a "e")
		//-- ub (igual valor a "e")
		
        int* lb = lower_bound(A, A + n, e);
        int* ub = upper_bound(A, A + n, e);
		
        int high = ub - A;
        lb--;
        int low = lb - A;
		
        if((lb == A + n) || (lb - A < 0)) cout<<"X "<<A[high]<<endl;
        else{
			if(ub == A + n) cout<<A[low]<<" X"<<endl;
			else cout<<A[low]<<" "<<A[high]<<endl;;
		}
    }
 
    return 0;
}