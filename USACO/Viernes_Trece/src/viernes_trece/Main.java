/*
ID: edison11
LANG: JAVA
TASK: friday
*/
package viernes_trece;
import java.util.*;
import java.io.*;
class Main {
    public static int APrimero(int A,int M,int dia){
        int Ndias = 0;
        if(M == 4 || M == 6 || M == 9 || M == 11 ) Ndias = 30;
        if(M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) Ndias = 31;
        if(M == 2)

        if(A % 100 == 0 ){
          if(A % 400 == 0) Ndias = 29;
          else Ndias = 28;
        }
        else{
            if(A % 4 == 0) Ndias = 29;
            else Ndias = 28;
         }
        return (Ndias + dia) % 7;
    }
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        RandomAccessFile f = new RandomAccessFile ("D:/friday.in.txt", "r");
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("D:/friday.out")));
        int M = 0,A = 1900,dia = 0,N,meses;
        int[] D = new int[7];
        N = Integer.parseInt(f.readLine());
        meses = 12 * N;

        for (int i= 0; i < meses; i++) {
           if(dia - 2 < 0){
               D[7 + dia - 2]++;
            }
           else{
               D[dia - 2]++;
            }
           M++;
           dia = APrimero(A, M, dia);
           if(M == 12){
               M = 0;
               A++;
           }

        }
        
        out.println(D[5] + " "+ D[6] + " "+ D[0] + " " +D[1] + " "+ D[2] + " "+D[3] + " " + D[4]);
        out.close();
        System.exit(0);
        
    }

}
