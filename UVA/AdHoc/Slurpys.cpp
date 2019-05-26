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
bool Slumps(string p){
    int T = p.length ();
	
    if ( T < 3 || (p [0] != 'D' && p [0] != 'E') || p [1] != 'F' ) return false;
	
    int i = 2;
    while ( p [i] == 'F' ) i++;

    if ( i + 1 == T && p [i] == 'G' ) return true;
    else return Slumps(p.substr (i, T - i));
}

bool Slimps(string p){
    int T = p.length ();
    
	if ( T < 2 || p [0] != 'A' ) return false;

    if ( T == 2 && p [1] == 'H' ) return true;
	
    if ( p [T - 1] != 'C' ) return false;
	
    if ( p [1] == 'B' ) return Slimps(p.substr (2, T - 3));
    else return Slumps(p.substr (1, T - 2));
}

int main (){
    int Casos;
    scanf ("%d", &Casos);
    cout << "SLURPYS OUTPUT" << endl;
    while ( Casos-- ) {
        string p;
        cin >> p;
        bool ans = false;

        for ( int i = p.length () - 1; i >= 0; i-- ) {
            if ( p[i] == 'C' || p[i] == 'H' ) {
                ans = Slimps(p.substr (0, i + 1)) && Slumps(p.substr (i + 1, p.length () - i - 1));
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}