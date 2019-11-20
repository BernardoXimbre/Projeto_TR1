GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include

IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -g -ftest-coverage -fprofile-arcs -lm

GTEST_VALGRIND = valgrind --leak-check=full
CPPLINT = cpplint
CPPCHECK = cppcheck --enable=warning
GCOV = gcov

G++_FLAGS = -I $(GOOGLE_TEST_INCLUDE)
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread

ODIR=obj

SIMULADOR = Simulador
TEST = Teste

TEST_CAMADA_FISICA = Testa_CamadaFisica
TEST_CAMADA_ENLACE = Testa_CamadaEnlace

CAMADA_FISICA = CamadaFisica
CAMADA_ENLACE = CamadaEnlace

_DEPS = $(CAMADA_FISICA).hpp $(CAMADA_ENLACE).hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(CAMADA_FISICA).o $(CAMADA_ENLACE).o $(TEST_CAMADA_FISICA).o $(TEST_CAMADA_ENLACE).o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_OBJ2 = $(CAMADA_FISICA).o $(CAMADA_ENLACE).o $(SIMULADOR).o
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

$(SIMULADOR): $(OBJ2)
	$(CC) -o $@ $^ $(LD_FLAGS) $(CFLAGS)
	./$(SIMULADOR)

$(TEST): $(OBJ)
	$(CC) -o $@ $^ $(LD_FLAGS) $(CFLAGS)
	$(GTEST_VALGRIND) ./$(TEST)
	$(CPPLINT) *.cpp
	$(CPPCHECK) *.cpp
	$(GCOV) -n $(ODIR)/*.gcda
	./$(TEST)
	
	

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $(G++_FLAGS) $< $(CFLAGS)

clean:
	rm -f $(ODIR)/*.* $(SIMULADOR) $(TEST) core $(INCDIR)/*~