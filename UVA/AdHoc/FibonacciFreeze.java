import java.math.BigInteger;
import java.util.Scanner;
public class Main {
	
	public static BigInteger[] fib(int n) {
		BigInteger[] fib = new BigInteger[n + 1];
		fib[0] = BigInteger.ZERO;
		fib[1] = BigInteger.ONE;
		for (int i = 2; i <= n; i++) 
			fib[i]= fib[i-1].add(fib[i-2]);
		return fib;
	}
	
	public static void main(String[] args) {
		BigInteger[] fib = fib(5001);
		Scanner in= new Scanner(System.in);
		while(in.hasNext()){
			int n = in.nextInt();
			System.out.printf("The Fibonacci number for %d is %d\n", n, fib[n] );
		}
	}
}