CC=g++
CC_FLAGS= -Wall -ansi -pedantic
MSG = @echo "Compilation de '$@' a partir de '$^'"

PROG = pop
SOURCES = cellule.cpp population.cpp population-main.cpp

all : $(PROG)

cellule.o: cellule.cpp
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

population.o: population.cpp 
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

population-main.o: population-main.cpp 
	$(MSG)
	$(CC) $(CC_FLAGS) -c $<

$(PROG): $(SOURCES:.cpp=.o)
	$(MSG)
	$(CC) $(SOURCES:.cpp=.o) -o $(PROG)

clean:
	rm -rf $(SOURCES:.cpp=.o) $(PROG) *~
