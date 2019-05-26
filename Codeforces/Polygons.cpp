#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;
#define EPS 1.0e-8
#define Vector Point
struct Point{
    double x, y;
    Point(){}
    Point(double a, double b) { x = a; y = b; }
    double mod2() { return x*x + y*y; }
    double mod()  { return sqrt(x*x + y*y); }
    Point ort()   { return Point(-y, x); }
    Point unit()  { double k = mod(); return Point(x/k, y/k); }
};

Point operator +(const Point &a, const Point &b){return Point(a.x + b.x, a.y + b.y);}
Point operator -(const Point &a, const Point &b){return Point(a.x - b.x, a.y - b.y);}
Point operator /(const Point &a, double n){return Point(a.x/n, a.y/n);}
Point operator *(const Point &a, double n){return Point(a.x*n, a.y*n);}
bool operator ==(const Point &a, const Point &b){return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;}
bool operator !=(const Point &a, const Point &b){return !(a==b);}
bool operator <(const Point &a, const Point &b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
double cross(const Vector &A, const Vector &B){return A.x * B.y - A.y * B.x;}
double area(const Point &A, const Point &B, const Point &C){return cross(B - A, C - A);}
vector <Point> ConvexHull(vector <Point> &P){
    sort(P.begin(),P.end());
    int n = P.size(),k = 0;
    Point H[2*n];
    
    for(int i=0;i<n;++i){
        while(k>=2 && area(H[k-2],H[k-1],P[i]) < 0) --k;
        H[k++] = P[i];
    }
    
    for(int i=n-2,t=k;i>=0;--i){
        while(k>t && area(H[k-2],H[k-1],P[i]) < 0) --k;
        H[k++] = P[i];
    }
    
    return vector <Point> (H,H+k-1);
}

bool onSegment(const Point &A, const Point &B, const Point &P){
    return abs(area(A, B, P)) < EPS &&
            P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x) &&
            P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y);
}

bool intersects(const Point &P1, const Point &P2, const Point &P3, const Point &P4){
    double A1 = area(P3, P4, P1);
    double A2 = area(P3, P4, P2);
    double A3 = area(P1, P2, P3);
    double A4 = area(P1, P2, P4);
    
    if( ((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) && 
        ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0))) 
            return true;
    
    else if(A1 == 0 && onSegment(P3, P4, P1)) return true;
    else if(A2 == 0 && onSegment(P3, P4, P2)) return true;
    else if(A3 == 0 && onSegment(P1, P2, P3)) return true;
    else if(A4 == 0 && onSegment(P1, P2, P4)) return true;
    else return false;
}

bool isInConvex(vector <Point> &A, const Point &P){
    for(int i=0; i<A.size(); i++)
        if(area(A[i], A[(i+1)%A.size()], P) <= 0)
            return false;
    return true;
}

Point norm(const Point &A, const Point &O){
    Vector V = A - O;
    V = V * 10000000000.0 / V.mod();
    return O + V;
}

bool isInConvex(vector <Point> &A, vector <Point> &B){
    if(!isInConvex(A, B[0])) return 0;
    else
    {
        int n = A.size(), p = 0;
        
        for(int i=1; i<B.size(); i++)
        {
            while(!intersects(A[p], A[(p+1)%n], norm(B[i], B[0]), B[0])) p = (p+1)%n;
            
            if(area(A[p], A[(p+1)%n], B[i]) <= 0) return 0;
        }
        
        return 1;
    }
}
int main(){
    int n, m;
    while(scanf("%d", &n) == 1){
        vector <Point> A(n);
        for(int i=0; i<n; i++)
            scanf("%lf %lf", &A[i].x, &A[i].y);
        reverse(A.begin(), A.end());
        
        scanf("%d", &m);
        vector <Point> B(m);
        for(int i=0; i<m; i++)
            scanf("%lf %lf", &B[i].x, &B[i].y);
        B = ConvexHull(B);
        
        if(isInConvex(A, B)) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}