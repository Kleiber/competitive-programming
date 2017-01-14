/*
ID: edison11
LANG: JAVA
TASK: beads
*/
package collar_roto;
import java.util.*;
import java.io.*;
class Main {

    public static char color(String co,int i){
        char color = co.charAt(i);
        if(color == 'w'){
            boolean f = false;
            while(!f && i< co.length()){
                if(co.charAt(i) != 'w'){
                    color = co.charAt(i);
                    f = true;
                }
                i++;
            }
        }
        return color;
    }

    public static int cantidad(String Co,int i){
        int cantidad = 1;
        char c = color(Co,i);
        int d = 0; 
        while(d != 2 && cantidad < Co.length()){
            
            if(i >= Co.length())
                i = 0;
            if(Co.charAt(i) == c || Co.charAt(i) == 'w' )
                cantidad++;
            else {
                c = color(Co,i);
                d++;
            }

            
            i++;
        }
        return cantidad;
    }
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        RandomAccessFile f = new RandomAccessFile ("D:/beads.in.txt", "r");
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("D:/beads.out")));
        int c,max = 0,
        n = Integer.parseInt(f.readLine());
        String Co = f.readLine();
        for (int i= 0; i < n; i++) {
            c = cantidad(Co, i);
            if(c> max)
                max = c;
        }
        out.println(max);
        out.close();             
        System.exit(0);
    }

}
