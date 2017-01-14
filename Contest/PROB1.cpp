#include<bits/stdc++.h>
using namespace std;
string romanos [4000 + 5] = { "0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};

int main() {
    for(int i = 11; i < 4000; i++) {
        int num = i;
        while(num){
            
            if (num >= 900 && num < 4000) {
                if (num/100 == 9){
					romanos[i] += "CM";
					num -= 900;
				}else{
					romanos[i] += "M";
					num -= 1000;
				}
            }

            if (num >= 400 && num < 900) {
                if (num/100 == 4){
					romanos [i] += "CD";
					num -= 400;
				}else{
					romanos[i] += "D";
					num -= 500;
				}
            }

            if (num >= 90 && num < 400) {
                if (num/10 == 9){
					romanos[i] += "XC";
					num -= 90;
				}else{
					romanos[i] += "C";
					num -= 100;
				}
            }

            if (num >= 40 && num < 90){
                if (num/10 == 4){
					romanos[i] += "XL";
					num -= 40;
				}else{
					romanos[i] += "L";
					num -= 50;
				}
            }

            if ( num >= 1 && num < 40 ) {
                for ( int j = 10; j >= 1; j-- ){
                    if (num >= j){ 
						romanos[i] += romanos[j];
						num -= j;
						break;
					}
				}
            }
        }
    }

    string s;

    while(cin >> s){
        if (isdigit(s[0])) cout << romanos[atoi(s.c_str())]<<endl;
        else {
            for(int i = 1; i < 4000; i++){
                if (romanos[i] == s) {
					cout<<i<<endl;
					break;
				}
            }
        }
    }

    return 0;
}
