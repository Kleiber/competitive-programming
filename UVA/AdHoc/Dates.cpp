#include<iostream>
#include<string>
#include<stdlib.h>
#include<map>
using namespace std;
map<string,int> M;
map<int,string> P;

int day(string s, int a){
	int d = M[s];
	if(d == 1 || d == 3 || d == 5 || d == 7 || d == 8 || d == 10 || d == 12) return 31;
	else{
		if(d == 4 || d == 6 || d == 9 || d == 11) return 30;
		else{
			if((a % 400 == 0) || (a % 4 == 0 &&  a % 100 != 0)) return 29;
			else return 28;
		}
	}
}
int main(){
	M["January"]=1;M["February"]=2;M["March"]=3;M["April"]=4;M["May"]=5;M["June"]=6;M["July"]=7;M["August"]=8;
	M["September"]=9;M["October"]=10;M["November"]=11;M["December"]=12;
	
	P[1]="January";P[2]="February";P[3]="March";P[4]="April";P[5]="May";P[6]="June";P[7]="July";P[8]="August";
	P[9]="September";P[10]="October";P[11]="November";P[12]="December";
	
	int c,caso = 0;
	cin>>c;
	while(c--){
		caso++;
		string linea,m;
		int a,d,ind1,ind2,s;
		cin>>linea;
		cin>>s;
		ind1 = linea.find('-');
		ind2 = linea.find('-',ind1 + 1);
		a = atoi(linea.substr(0,ind1).c_str());
		m = linea.substr(ind1 + 1,ind2 - 1 - ind1);
		d = atoi(linea.substr(ind2 + 1,linea.size() - ind2 -1).c_str());

		while(s > 0){
			//cout<<m<<" "<<day(m,a)<<" "<<a<<endl;
			int aux = s;
			s = s - (day(m,a) - d);
			if(s > 0){
				if(M[m] == 12) {a++; m = P[1]; d = 0;}
				else {m = P[M[m] + 1]; d = 0;}
			}
			else d += aux;
		}
		
		if(d < 10){
			char n = (char)d + '0';
			string d1 = "0";
			d1+=n;
			cout<<"Case "<<caso<<": "<<a<<"-"<<m<<"-"<<d1<<endl;
		}
		else
			cout<<"Case "<<caso<<": "<<a<<"-"<<m<<"-"<<d<<endl;
	}
	return 0;
}
