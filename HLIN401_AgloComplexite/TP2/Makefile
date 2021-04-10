DOT=$(wildcard *.dot)

tests: tests.cc Tas.cc
	g++ -Wpedantic $^ -o $@

clean:
	rm -f $(DOT) $(DOT:.dot=.pdf)
