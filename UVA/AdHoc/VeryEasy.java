import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int N,A;
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            N = in.nextInt();
            A = in.nextInt();
            
            BigInteger sum = BigInteger.ZERO;
            for(int  i = 1; i < N + 1; i++){
                BigInteger aux = BigInteger.valueOf(A).pow(i).multiply(BigInteger.valueOf(i));
                sum = sum.add(aux);
            }
            System.out.println(sum);
        }
    }
}
