/*
ID: edison11
LANG: JAVA
TASK: gift1
*/
package dadores_glotones;
import java.util.*;
import java.io.*;

public class Main {

    public static int Buscar(String[] Gr,String N)
    {
        int in = -1;
        for (int i=0; i < Gr.length; i++) {
            if(Gr[i].equals(N)){
                in = i ;
                break;
            }
        }
        return in;
    }

    public static void main(String[] args) throws IOException {

       RandomAccessFile f = new RandomAccessFile ("gift1.in", "r");
       PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));

       int numero,cantidad,parte,sobra,in1,in2;
       int n = Integer.parseInt(f.readLine());
       String[] Gr = new String[n];
       int[] Ga = new int[n];
       for (int i= 0; i < n; i++) {
            Gr[i]=f.readLine();
       }

        for (int i= 0; i < n; i++) {
            in1 = Buscar(Gr,f.readLine());
            String s = f.readLine();                     
            StringTokenizer st = new StringTokenizer(s);
            cantidad = Integer.parseInt(st.nextToken());
            numero = Integer.parseInt(st.nextToken());
            parte = numero>0? cantidad/numero:0;
            sobra = numero>0? cantidad%numero:0;
            Ga[in1] = Ga[in1] + (-1)*cantidad + sobra;
            for (int j= 0; j < numero; j++) {
               in2 = Buscar(Gr,f.readLine());
               Ga[in2] = Ga[in2] + parte;
            }
        }

        for (int i= 0; i < Gr.length; i++) {
            out.println(Gr[i] + " " + Ga[i]);
        }

        out.close();
        System.exit(0);

    }

}
