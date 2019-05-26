#include<iostream>
using namespace std; 
int main () 
{
	int pos,i=0,num,den;
	cin>>pos;

	while(i*(i+1)/2 < pos)
		i++;
	//--i es par tonces der a izq caso contrario iz q a der
	int cont =i*(i-1)/2 ;
	if(i % 2 == 0){
		num = 1; den = i;
		for (int j = 0 ; j < i; j++){
			if(cont == pos -1) {
				cout<<"TERM "<<pos<<" IS "<<num<<"/"<<den;
				break;
			}
			num = num +1;
			den  =  den - 1;
			cont ++;
		}
	}
	else{
		num = i; den = 1;
		for (int j = 0 ; j < i; j++){
			if(cont == pos -1)  {
				cout<<"TERM "<<pos<<" IS "<<num<<"/"<<den;
				break;
			}
			num = num -1;
			den  =  den + 1;
			cont ++;
		}
	}
	return 0;
}