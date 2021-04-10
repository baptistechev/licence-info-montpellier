CC=g++
CC_FLAGS= -Wall -ansi -pedantic
MSG = @echo "Compilation de '$@' a partir de '$^'"

PROG = test
SOURCES = monome.cpp test.cpp polynome.cpp

all : $(PROG)

monome.o: monome.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

test.o: test.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

polynome.o: polynome.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

$(PROG): $(SOURCES:.cpp=.o)
	$(MSG)
	$(CC) $(SOURCES:.cpp=.o) -o $(PROG)

clean:
	rm -rf $(SOURCES:.cpp=.o) $(PROG) *~
