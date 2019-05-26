#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>  
#include <cstdlib>
using namespace std;
int main()
{
	double n1,n2;
	cin>>n1>>n2;
	while (n1 != 0 || n2 != 0){
	long long cont = 0;
	double aux = 1, t1 = 1,t2 =2;
		while(t1 <= n2){
			if(t1 >= n1 && t1 <= n2) cont++;
			cout<<aux<<" ";
			aux = t2;
			t2 = t1 + t2; 
			t1 = aux;
		}
		cout<<cont<<endl;
		cont = 0;
		cin>>n1>>n2;
	}
	
    return 0;
}