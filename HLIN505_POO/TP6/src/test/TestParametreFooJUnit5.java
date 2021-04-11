package test;

import static org.hamcrest.CoreMatchers.is;

import static org.junit.jupiter.api.Assertions.*;

import java.util.stream.Stream;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.CsvSource;
import org.junit.jupiter.params.provider.MethodSource;
import static org.hamcrest.MatcherAssert.assertThat;
class TestParametreFooJUnit5 {

	public TestParametreFooJUnit5() {
		System.out.println("constr");
	}
	SUT sut;
	@Test
	void test() {
		fail("Not yet implemented");
	}
	
	@DisplayName("Test foo avec ")
    @ParameterizedTest(name = "{index} : x={0}, y={1}, z={2}, t={3}")
    @MethodSource("xyztresProvider")
	public void testFoo(int x, int y, int z, int t, int res) {
		sut=new SUT(x, y, z);
		assertThat(sut.foo(t), is(res));
	}
	
	 private static Stream<Arguments> xyztresProvider() {
	        return Stream.of(
	                Arguments.of(1, 3, 5, 0, 1),
	                Arguments.of(1, 5, 3, 0, 1),
	                Arguments.of(1, 0, 0, 0, 1),
	                Arguments.of(1, 1, 0, 1, 0),
	                Arguments.of(1, 5, 1, 2, 1),
	                Arguments.of(1, 5, 3, 1, 5),
	                Arguments.of(1, 5, 2, 2, 5),
	                Arguments.of(5, 3, 8, 4, 5)
	        );}
	 
	 @ParameterizedTest
	 @CsvSource(value = {"1, 3, 5, 0, 1", "1, 5, 3, 0, 1", "1, 0, 0, 0, 1", 
			 "1, 1, 0, 1, 0", "1, 5, 1, 2, 1", "1, 5, 3, 1, 5", "1, 5, 2, 2, 5","5, 3, 8, 4, 5"}, delimiter = ',')
		void testFooBis(int x, int y, int z, int t, int res) {
		 sut=new SUT(x, y, z);
			assertThat(sut.foo(t), is(res));
		}
}
