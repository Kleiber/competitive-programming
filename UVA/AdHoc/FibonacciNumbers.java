import java.util.Scanner;
import java.math.BigInteger;
public class Main {
	public static void main(String[] args) {
		int n;
		Scanner keyboard = new Scanner(System.in);
		BigInteger[] F = new BigInteger[5000];
		F[1] = BigInteger.valueOf(1);
		F[2] = BigInteger.valueOf(1);
		for(n = 3; n < 5000; n++) {
			F[n] = F[n-1].add(F[n-2]);
		}
		while(keyboard.hasNext()) {
			n = keyboard.nextInt();
			System.out.println(F[n]);
		}
	}
} 