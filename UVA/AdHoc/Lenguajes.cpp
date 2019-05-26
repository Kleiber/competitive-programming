#include<iostream>
using namespace std;
int main() {
	int n,a,c,s = 0;
	cin >>  n;
	int j= 1;
	while(n != 0)
	{
		for(int  i = 0;i<n;i++){	cin>>a; s = s +a;}
		cout<<"Case "<<j<<": "<<endl;
		//--primer caso si la division es un numero entero
		if(s%n == 0)
			if(s/n > 0)
				cout << s/n <<endl;
			else
				cout <<"- "<<(-1)* s/n <<endl;
		else
		{
			//--Simplificando
			int menor;
			if(s > n)
				menor = n;
			else
			    menor = s;
				
			if(menor < 0) menor = (-1)*menor;
			
			for(int  k = 2;k<=menor;k++){
				if(n % k == 0 && s % k== 0)
				{
					n = n / k;
					s = s / k;
				}
			}
			//--cantidad de digitos
			int aux = n,d = 0;
			string e33="",e11="",e1 ="",e2="",e3="";
			
			while(aux / 10 > 0)
			{
					d++;					
					aux = aux / 10;
			}
			for(int  k = 0;k<d+1;k++)
			{
					e2 = e2 + "-";
					if(k != d)
						e1 = e1 +" ";
			}		
			//--segundo caso cuando se pueden simplificar
			int avg = avg = s/n;
			if(avg < 0) avg = (-1)*s/n;
				
			if(avg < 1)
			{
				if(s < 0)
				{
						cout <<"  "<<e1<<(-1)*s<<endl;
						cout <<"- "<<e2<<endl;
						cout <<"  "<<n<<endl;
				}
				else
				{
					cout <<e1<<s<<endl;
					cout <<"-"<<endl;
					cout <<n<<endl;
				}
			}
			else
			{
				//--asiganmos los espacios
				int d1 =0;
				if(s/n < 0)
					aux = (-1)*s/n;
				else
					aux = s/n;
					
				while(aux / 10 > 0)
				{
					d1++;
					aux = aux / 10;
				}
				
				for(int  k = 0;k<d1+1;k++)
				{
					e11 = e11+ " ";
					e33=e33+" ";
					if(k != d1)
						e3 = e3 +" ";
				}	
				if(d1> 0 || d >0)
					e11 = e11+" ";
				//--tercer convertir a un numero mixto s/n > 1
				if(s < 0)
				{
					a = (-1)*s/n;
					c = (-1)*s % n;
					cout<<"  "<<e11<<c<<endl;
					cout<<"- "<<a<<e2<<endl;
					cout<<"  "<<e33<<n<<endl;
				}
				else
				{
					a = s/n;
					c = s % n;
					cout<<e11<<c<<endl;
					cout<<a<<e2<<endl;
					cout<<e33<<n<<endl;
				}
			}
		}
		
		cin>>n;
		s = 0;
		j++;
	}
	return 0;
}
