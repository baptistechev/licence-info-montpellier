CXX=g++
CXXFLAGS=-Wall -ansi -pedantic -g
#CXXFLAGS+=-DOP_AVEC_METHODE
CXXFLAGS+=-DSUBST_OPTIMISEE

all: all-real

DEPEND=.depend

TEST_AFFECTATION_PROG=test-affectation
TEST_AFFECTATION_SOURCES=monome.cpp polynome.cpp test-affectation.cpp
TEST_AFFECTATION_HEADERS=monome.h polynome.h

PROGS = $(TEST_AFFECTATION_PROG)
SOURCES = $(TEST_AFFECTATION_SOURCES)
HEADERS = $TEST_AFFECTATION_HEADERS)

$(TEST_AFFECTATION_PROG): $(TEST_AFFECTATION_SOURCES:.cpp=.o)

ifeq ($(wildcard $(DEPEND)), )
all-real: $(DEPEND)
	make
else

all-real: $(PROGS)

include $(DEPEND)

endif

$(PROGS):
	$(CXX) $^ -o $@

$(DEPEND): $(SOURCES)
	$(CXX) -MM $^ > $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(SOURCES:.cpp=.o) $(PROGS) $(DEPEND) *~
        
