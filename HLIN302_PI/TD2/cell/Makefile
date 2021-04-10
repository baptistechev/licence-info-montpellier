CC=g++
CC_FLAGS= -Wall -ansi -pedantic
MSG = @echo "Compilation de '$@' a partir de '$^'"

PROG = cellule
SOURCES = Cellule.cpp cellule-test.cpp

all : $(PROG)

Cellule.o: Cellule.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

cellule-test.o: cellule-test.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

$(PROG): $(SOURCES:.cpp=.o)
	$(MSG)
	$(CC) $(SOURCES:.cpp=.o) -o $(PROG)

clean:
	rm -rf $(SOURCES:.cpp=.o) $(PROG) *~
