CC=g++
CC_FLAGS= -Wall -ansi -pedantic
MSG = @echo "Compilation de '$@' a partir de '$^'"

PROG = test-itv
SOURCES = itv.cpp itv-main.cpp

all : $(PROG)

itv.o: itv.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

itv-main.o: itv-main.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

$(PROG): $(SOURCES:.cpp=.o)
	$(MSG)
	$(CC) $(SOURCES:.cpp=.o) -o $(PROG)

clean:
	rm -rf $(SOURCES:.cpp=.o) $(PROG) *~
