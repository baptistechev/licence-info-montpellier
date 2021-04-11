package test;

import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.MatcherAssert.assertThat;

import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

public class TestParametreBarJUnit5 {

	public TestParametreBarJUnit5() {
		System.out.println("constr");
	}
	SUT sut;
	
	@ParameterizedTest
	@CsvSource(value = {"1, 3, 5","2, 4, 5"}, delimiter = ',')
	void testFooBar(int x, int y, int z) {
	 	sut=new SUT(x, y, z);
		sut.bar();
		assertThat(sut.foo(x), is(y));
		assertThat(sut.foo(z), is(x));
	}
	
}
