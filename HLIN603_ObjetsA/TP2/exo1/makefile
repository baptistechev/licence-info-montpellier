GPP=g++
SRC=Compte.cc CompteRenum.cc CompteDepot.cc CompteDepotRemun.cc CompteDepotCC.cc CompteDepotRemunCC.cc main.cc
OBJ=$(SRC:%.cc=%.o)
EXE=main

all: $(OBJ)
		$(GPP) -o $(EXE) $(OBJ)

clean:
		rm -f *~ *.o $(EXE)

.SUFFIXES: .cc .o

%.o: %.cc
		$(GPP) -c $<