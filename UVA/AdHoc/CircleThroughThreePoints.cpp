#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<algorithm>
#define MAX 3
using namespace std;
struct Punto{
	double x;
	double y;
};
double M[MAX][MAX],Aux[MAX][MAX];
double R[MAX];

double Det(){
	double ans;
	ans =  M[0][0]*M[1][1]*M[2][2];
	ans += M[0][1]*M[1][2]*M[2][0];
	ans += M[1][0]*M[2][1]*M[0][2];
	ans -= M[0][2]*M[1][1]*M[2][0];
	ans -= M[0][1]*M[1][0]*M[2][2];
	ans -= M[0][0]*M[2][1]*M[1][2];
	return ans;
}

double DetM(){
	double ans;
	ans =  Aux[0][0]*Aux[1][1]*Aux[2][2];
	ans += Aux[0][1]*Aux[1][2]*Aux[2][0];
	ans += Aux[1][0]*Aux[2][1]*Aux[0][2];
	ans -= Aux[0][2]*Aux[1][1]*Aux[2][0];
	ans -= Aux[0][1]*Aux[1][0]*Aux[2][2];
	ans -= Aux[0][0]*Aux[2][1]*Aux[1][2];
	return ans;
}

double Calcular(int n){
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			Aux[i][j] = M[i][j];
		}
	}
	for(int i = 0; i < MAX; i++) Aux[i][n] = R[i];
	double ans = DetM();
	return ans;
}

int main(){
	Punto A,B,C,Centro;
	double c,d,e,det,radio;
	while(cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y){
		memset(M,0,sizeof(M));
		memset(R,0,sizeof(R));
		M[0][0] = A.x; M[0][1] = A.y; M[0][2] = 1;
		M[1][0] = B.x; M[1][1] = B.y; M[1][2] = 1;
		M[2][0] = C.x; M[2][1] = C.y; M[2][2] = 1;
		R[0] = (-1)*(pow(A.x,2) + pow(A.y,2)); 
		R[1] = (-1)*(pow(B.x,2) + pow(B.y,2));
		R[2] = (-1)*(pow(C.x,2) + pow(C.y,2));
	
		det = Det();
		c = Calcular(0)/det;
		d = Calcular(1)/det;
		e = Calcular(2)/det;
		
		Centro.x = (-1)*(c/2);
		Centro.y = (-1)*(d/2);
		radio = pow(pow(c/2,2) + pow(d/2,2) - e,0.5);
		
		//printf("%.3f %.3f %.3f\n", Centro.x,Centro.y,radio); 
		//printf("%.3f %.3f %.3f\n", c,d,e); 
		
		cout << "(x ";
        if(Centro.x < 0){
			cout << "+ ";
			printf("%.3f",fabs(-1*Centro.x));
			cout << ")^2 + (y ";
        }else{
            cout << "- " ;
            printf("%.3f",fabs(Centro.x));
            cout << ")^2 + (y ";
        }if(Centro.y < 0){
			cout << "+ ";
			printf("%.3f",fabs(-1*Centro.y));
			cout << ")^2 = ";
		}else{
			cout << "- ";
			printf("%.3f",fabs(Centro.y));
			cout << ")^2 = ";
		}
		printf("%.3f^2\n",radio);
 
        cout << "x^2 + y^2 ";
        if(-2 * Centro.x < 0) cout <<"- ";
        else cout <<"+ ";
		
        printf("%.3fx ",fabs(-2*Centro.x));
		
        if(-2 * Centro.y <0) cout<<"- ";
        else cout <<"+ ";
		
        printf("%.3fy ",fabs(-2*Centro.y));
		
        if(Centro.y * Centro.y + Centro.x * Centro.x - radio * radio < 0) cout << "- ";
        else cout <<"+ ";
		
        printf("%.3f = 0\n\n",fabs(Centro.y * Centro.y + Centro.x * Centro.x - radio * radio));
	}
	return 0;
}