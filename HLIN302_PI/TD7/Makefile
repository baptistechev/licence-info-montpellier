CC=g++
CC_FLAGS= -Wall -ansi -pedantic
MSG = @echo "Compilation de '$@' a partir de '$^'"

PROG = test
SOURCES = cellule.cpp myVectorMain.cpp

all : $(PROG)

cellule.o: cellule.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

myVectorMain.o: myVectorMain.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

$(PROG): $(SOURCES:.cpp=.o)
	$(MSG)
	$(CC) $(SOURCES:.cpp=.o) -o $(PROG)

clean:
	rm -rf $(SOURCES:.cpp=.o) $(PROG) *~
