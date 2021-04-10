GPP=g++
SRC=Vers.cc Strophe.cc mainStrophe.cc
OBJ=$(SRC:%.cc=%.o)
EXE=mainStrophe

all: $(OBJ)
		$(GPP) -o $(EXE) $(OBJ)

clean:
		rm -f *~ *.o $(EXE)

.SUFFIXES: .cc .o

%.o: %.cc
		$(GPP) -c $<