import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {  
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            BigInteger B = in.nextBigInteger();
            BigInteger P = in.nextBigInteger();
            BigInteger M = in.nextBigInteger();
            
            BigInteger R = B.modPow(P, M);
            System.out.println(R);
        }
    }
}