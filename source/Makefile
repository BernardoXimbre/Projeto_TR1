
GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include

IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -g -ftest-coverage -fprofile-arcs

GTEST_VALGRIND = valgrind
CPPLINT = cpplint
CPPCHECK = cppcheck --enable=warning
GCOV = gcov

G++_FLAGS = -I $(GOOGLE_TEST_INCLUDE)
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread

ODIR=obj

TEST_PROGRAM = Testa_Programa
NAME_PROGRAM = CamadaFisica

_DEPS = $(NAME_PROGRAM).hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(NAME_PROGRAM).o $(TEST_PROGRAM).o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(TEST_PROGRAM): $(OBJ)
	$(CC) -o $@ $^ $(LD_FLAGS) $(CFLAGS)
	$(GTEST_VALGRIND) ./$(TEST_PROGRAM)
	$(CPPLINT) *.cpp
	$(CPPCHECK) *.cpp
	$(GCOV) -n $(ODIR)/*.gcda
	
	
$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $(G++_FLAGS) $< $(CFLAGS)

$(CPPLINT):
	

gcov:
	
clean:
	rm -f $(ODIR)/*.* $(TEST_PROGRAM) core $(INCDIR)/*~