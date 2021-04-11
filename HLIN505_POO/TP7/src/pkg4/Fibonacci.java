package pkg4;

import java.util.function.Supplier;
import java.util.stream.Stream;

public class Fibonacci {

	public Stream<Integer> generateFib() {
		Stream<Integer> s  = Stream.generate(new Supplier<Integer>() {
			
			private int rang = 0;
			
			public int fib(int n) {
			     if (n <= 1) return n;
			     else return fib(n-1) + fib(n-2);
			 }
			
			@Override
			public Integer get() {
				return fib(rang++);
			}
		});
		
		return s;
	}
	
	public void afficheFibonacci(int n) {
		generateFib().limit(n).forEach(System.out::println);
	}
	
	public void afficherPairFibonacci(int n) {
		generateFib().filter(i ->i%2==0).limit(n).forEach(System.out::println);
	}
}
