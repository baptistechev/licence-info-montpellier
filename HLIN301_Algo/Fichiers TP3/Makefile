CC = g++
CFLAGS = -Wall -pedantic -std=c++0x -c

tp3 : 	fichierTP3.o progListeSC.o mainTP3.o
	${CC} -o tp3 progListeSC.o fichierTP3.o mainTP3.o

progListeSC.o : progListeSC.cpp
	${CC} ${CFLAGS} progListeSC.cpp

fichierTP3.o : fichierTP3.cpp
	${CC} ${CFLAGS} fichierTP3.cpp

mainTP3.o : mainTP3.cpp fichierTP3.h progListeSC.h
	${CC} ${CFLAGS} mainTP3.cpp

clean:
	rm -rf *.o

