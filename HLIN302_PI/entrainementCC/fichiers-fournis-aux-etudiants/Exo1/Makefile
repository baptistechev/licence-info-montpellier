CXX=g++
CXXFLAGS=-Wall -ansi -pedantic -g

all: all-real

DEPEND=.depend

TEST_MONOME_PROG=test-monome
TEST_MONOME_SOURCES=monome.cpp test-monome.cpp
TEST_MONOME_HEADERS=monome.h

TEST_POLYNOME_PROG=test-polynome
TEST_POLYNOME_SOURCES=monome.cpp polynome.cpp test-polynome.cpp
TEST_POLYNOME_HEADERS=monome.h polynome.h

PROGS = $(TEST_MONOME_PROG) $(TEST_POLYNOME_PROG)
SOURCES = $(TEST_MONOME_SOURCES) $(TEST_POLYNOME_SOURCES)
HEADERS = $(TEST_MONOME_HEADERS) $(TEST_POLYNOME_HEADERS)

$(TEST_MONOME_PROG): $(TEST_MONOME_SOURCES:.cpp=.o)
$(TEST_POLYNOME_PROG): $(TEST_POLYNOME_SOURCES:.cpp=.o)

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
        