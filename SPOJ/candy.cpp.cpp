#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    while (1) {
        int candy[10001];
		int n,ans,suma;
        cin>>n;
        if(n==-1) return 0;
        for(int i = 0; i < n; i++) cin>>candy[i];
			
		sort(candy, candy + n);
		
		suma = 0;ans=0;
        for (int i = 0; i < n; i++) suma+=candy[i];
   
		if (suma % n != 0)
            cout<<-1<<endl;
        else {
            for (int i = 0; i < n; i++)
                if (candy[i] < suma/n)
                    ans = ans + suma/n - candy[i];
        cout<<ans<<endl;
        }
 
    }
    return 0;
}

