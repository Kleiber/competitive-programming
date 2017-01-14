package javaapplication18;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	public static void main(String args[]) {
		Scanner s = new Scanner(System.in);
		BigInteger zero = BigInteger.valueOf(0);
		BigInteger sum = BigInteger.valueOf(0);
		for(;;) {
			BigInteger b = s.nextBigInteger();
			if(b.equals(zero)) break;
			sum = sum.add(b);
		}
		System.out.println(sum.toString());
	}
}