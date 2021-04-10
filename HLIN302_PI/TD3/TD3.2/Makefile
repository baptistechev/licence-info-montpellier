CC=g++
CC_FLAGS= -Wall -ansi -pedantic
MSG = @echo "Compilation de '$@' a partir de '$^'"

PROG = pop
SOURCES = cellule.cpp population-vivante.cpp population-vivante-main.cpp

all : $(PROG)

cellule.o: cellule.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

population-vivante.o: population-vivante.cpp 
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

population-vivante-main.o: population-vivante-main.cpp 
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

$(PROG): $(SOURCES:.cpp=.o)
	$(MSG)
	$(CC) $(SOURCES:.cpp=.o) -o $(PROG)

clean:
	rm -rf $(SOURCES:.cpp=.o) $(PROG) *~
