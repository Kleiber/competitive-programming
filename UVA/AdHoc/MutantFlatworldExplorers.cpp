#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
bool visited [52] [52];
int x,y,row,col;
char dir;
bool pos;
using namespace std;
void update (char n){
    if ( dir == 'S' && n == 'R' )
        dir = 'W';
    else if ( dir == 'S' && n == 'L' )
        dir = 'E';
 
    else if ( dir == 'N' && n == 'R' )
        dir = 'E';
    else if ( dir == 'N' && n == 'L' )
        dir = 'W';
 
    else if ( dir == 'E' && n == 'R' )
        dir = 'S';
    else if ( dir == 'E' && n == 'L' )
        dir = 'N';
 
    else if ( dir == 'W' && n == 'R' )
        dir = 'N';
    else if ( dir == 'W' && n == 'L' )
        dir = 'S';
 
    if ( n == 'F' ) {
        switch ( dir ) {
            case 'N' :
            if ( row == y && visited[x][y])
                break;
            else if ( row == y && !visited[x][y]) {
                visited[x][y] = 1;
				cout<<x<<" "<<y<<" "<<dir<<" LOST"<<endl;
                pos = 1;
                break;
            }
            y++;
            break;
 
            case 'S' :
            if ( y == 0 && visited[x][y])
                break;
            else if ( y == 0 && !visited[x][y]) {
                visited[x][y] = 1;
                cout<<x<<" "<<y<<" "<<dir<<" LOST"<<endl;
                pos = 1;
                break;
            }
            y--;
            break;
 
            case 'E' :
            if ( col == x && visited[x][y])
                break;
            else if ( col == x && !visited[x][y]) {
                visited[x][y] = 1;
				cout<<x<<" "<<y<<" "<<dir<<" LOST"<<endl;
                pos = 1;
                break;
            }
            x++;
            break;
 
            case 'W' :
            if ( x == 0 && visited[x][y])
                break;
            else if ( x == 0 && !visited[x][y]) {
                visited [x][y] = 1;
				cout<<x<<" "<<y<<" "<<dir<<" LOST"<<endl;
                pos = 1;
                break;
            }
            x--;
        }
    }
}
 
int main (){
	memset(visited,0,sizeof(visited));
	cin>>col>>row;
    while ( cin>>x>>y>>dir) {
		string s;
        cin>>s;
        pos = 0;
        for ( int i = 0; s[i] && !pos; i++)update (s[i]);
        if (!pos) cout<<x<<" "<<y<<" "<<dir<<endl;
    }
    return 0;
}