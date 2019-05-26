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
#include<stdio.h>
#include<string.h>
#include <iostream>
#include <map>
#include <ctype.h>
using namespace std;

int main() {
    map<string, char> r;
    r[".-"] = 'A', r["-..."] = 'B', r["-.-."] = 'C';
    r["-.."] = 'D', r["."] = 'E', r["..-."] = 'F';
    r["--."] = 'G', r["...."] = 'H', r[".."] = 'I';
    r[".---"] = 'J', r["-.-"] = 'K', r[".-.."] = 'L';
    r["--"] = 'M', r["-."] = 'N', r["---"] = 'O';
    r[".--."] = 'P', r["--.-"] = 'Q', r[".-."] = 'R';
    r["..."] = 'S', r["-"] = 'T', r["..-"] = 'U';
    r["...-"] = 'V', r[".--"] = 'W', r["-..-"] = 'X';
    r["-.--"] = 'Y', r["--.."] = 'Z', r["-----"] = '0';
    r[".----"] = '1', r["..---"] = '2', r["...--"] = '3';
    r["....-"] = '4', r["....."] = '5', r["-...."] = '6';
    r["--..."] = '7', r["---.."] = '8', r["----."] = '9';
    r[".-.-.-"] = '.', r["--..--"] = ',', r["..--.."] = '?';
    r[".----."] = '\'', r["-.-.--"] = '!', r["-..-."] = '/';
    r["-.--."] = '(', r["-.--.-"] = ')', r[".-..."] = '&';
    r["---..."] = ':', r["-.-.-."] = ';', r["-...-"] = '=';
    r[".-.-."] = '+', r["-....-"] = '-', r["..--.-"] = '_';
    r[".-..-."] = '\"', r[".--.-."] = '@';
    int t, cases = 0;
    string in;
    cin >> t;
    cin.ignore(100, '\n');
    while(t--) {
        cases++;
        cout << "Message #" << cases << endl;
        getline(cin, in);
        int len = in.length(), cnt = 0;
        for(int i = 0; i < len; i++) {
            if(isspace(in[i])) {
                if(cnt == 1) {
                    cout << ' ';
                    cnt = 0;
                } else
                    cnt++;
                continue;
            }
            int j = i;
            string s = "";
            while(!isspace(in[j]) && j < len) {
                s += in[j];
                j++;
            }
            cout << r[s];
            cnt = 0;
            i = j-1;
        }
        cout << endl;
        if(t)
            cout << endl;

    }
    return 0;
}
using namespace std;
int main() {
	map<string,int>M;
	M[".-"]  =65; M[".---"]=74;  M["..."]    =83;	  M[".----"]=49;  M[".-.-.-"]=46;  M["---..."]    =58;
	M["-..."]=66;M["-.-"]    =75;  M["-"]    =84;	  M["..---"]=50;  M["--..--"]=44;  M["-.-.-."]    =59;
	M["-.-."]=67;M[".-.."]   =76;  M["..-"]  =85;	  M["...--"]=51;  M["..--.."]=63;  M["-...-"]	  =61;
	M["-.."] =68;M["--"]    =77;  M["...-"]  =86;	  M["....-"]=52;  M[".----."]=39;  M[".-.-."]     =43;
	M["." ]  =69;M["-."]     =78;  M[".--"]  =87;	  M["....."]=53;  M["-.-.--"]=33;  M["-....-"]	  =45;
	M["..-."]=70;M["---"]  =79;  M["-..-"]   =88;   M["-...."]=54;  M["-..-."] =47;  M["..--.-"]    =95;
	M["--."]=71;M[".--."]  =80;  M["-.--"] =89;   M["--..."]=55;  M["-.--."] =40;  M[".-..-."]    =34;
	M["...."]=72;M["--.-"]  =81;  M["--.."] =90;   M["---.."]=56;  M["-.--.-"]=41;  M[	".--.-."] =64;
	M[".."]  =73;M[".-."]    =82;  M["-----"]=48;   M["----."]=57;  M[".-..."] =38;
	
	string c,aux,res = "";
	int casos;
	cin>>casos;
	getline(cin,c);
	for(int i = 0; i<casos; i++){
		getline(cin,c);
		cout<<"Message #"<<i+1<<endl;
		for(int j = 0; j < c.size(); j++){
			if((int)c[j] != 32) aux += c[j];
			else {  
				res+=(char)M[aux];
				if(c[j+1] == 32){ res+=" " ;j++;}
				aux ="";
			}		
			if(j == c.size() -1){
				res+=(char)M[aux];  
				aux ="";
				cout<<res<<endl;
				if(i != 0) cout<<endl;
			}
		}
		res ="";
		aux ="";
	}
	
	return 0;
}