#include<bits/stdc++.h>
using namespace std;
int main(){
	int casos;
    cin>>casos;
    while(casos--){
		int t, n;
		cin>>t>>n;
		
        int l = 0;
		int h = 0;
        while(n--){
			int ant;
			cin>>ant;
            l = max(l, min(t - ant, ant));
            h = max(h, max(t - ant, ant));
        }
		cout<<l<<" "<<h<<endl;
    }
    return 0;
}











