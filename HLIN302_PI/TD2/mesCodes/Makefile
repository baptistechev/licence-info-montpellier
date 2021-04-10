CC=g++
CC_FLAGS= -Wall -ansi -pedantic
MSG = @echo "Compilation de '$@' a partir de '$^'"

PROG = test-Itv
SOURCES = Itv.cpp Itv-main.cpp

all : $(PROG)

Itv.o: Itv.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

Itv-main.o: Itv-main.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

$(PROG): $(SOURCES:.cpp=.o)
	$(MSG)
	$(CC) $(SOURCES:.cpp=.o) -o $(PROG)

clean:
	rm -rf $(SOURCES:.cpp=.o) $(PROG) *~
