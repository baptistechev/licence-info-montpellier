CC=g++
CC_FLAGS= -Wall -ansi -pedantic
MSG = @echo "Compilation de '$@' a partir de '$^'"

PROG = test
SOURCES = cellule.cpp tableauCell.cpp main.cpp triTas.cpp

all : $(PROG)

cellule.o: cellule.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

tableauCell.o: tableauCell.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

main.o: main.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

triTas.o : triTas.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

$(PROG): $(SOURCES:.cpp=.o)
	$(MSG)
	$(CC) $(SOURCES:.cpp=.o) -o $(PROG)

clean:
	rm -rf $(SOURCES:.cpp=.o) $(PROG) *~
