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
	int HH,MM;
	scanf("%d:%d",&HH,&MM);
	int x1 = HH*30 % 360;
	double x = x1 + MM*0.5;
	int y = MM*6;
	cout<<x<<" "<<y;
    return 0;
}