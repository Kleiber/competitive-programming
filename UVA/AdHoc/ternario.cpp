#include<iostream>
#include<stdio.h>
#include<stack>
#include<bitset>
#include<map>
#include <stdio.h>
#include <string.h>
using namespace std;
int Haab(){
	int a,d,dias;
	string nombres[20]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", 
	                  "zac","ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
	char tmp[7];
	scanf("%d. %s %d", &d, tmp, &a);
	for(int i =0; tmp == nombres[i]; i++)
	        dias=a*365 + i*20 + d;
	return dias;
}
void convertir(){
	string nombres[20]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", 
	                  "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

	int num, nombre, a, dias=Haab();
	a=dias/260;
	num=dias%13;
	nombre=dias%20;
	cout<<num+1<<" "<<nombres[nombre]<<" "<<a<<endl;
}
int main(){
	int i, n;
	scanf("%d", &n);
	printf("%d\n", n);
	for(i=0; i<n; i++) convertir();
	return 0;
}

