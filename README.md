# Projeto_TR1
## Requisitos para funcionamento

gcc version 7.3.0

	sudo apt-get update
	sudo apt-get install build-essential

GNU Make 4.1

	sudo apt-get install make

Gtest version 1.8.1

	sudo apt-get install cmake # install cmake
	cd /usr/src/gtest
	sudo cmake CMakeLists.txt
	sudo make
	sudo cp *.a /usr/lib

cpplint

	sudo apt-get install python-pip
	sudo pip install cpplint

Cppcheck 1.82

	sudo apt-get update
	sudo apt-get install cppcheck

Valgrind-3.13.0

	sudo apt-get update
	sudo apt-get install valgrind

### COMPILAÇÃO & TESTES

Abra o terminal e execute os seguintes comandos para executar

### SIMULAR

	cd Projeto_TR1/code/source/make Simulador

### TESTE UNITARIO

	cd Projeto_TR1/code/source/make Teste
### APAGAR TODOS OS OBJETOS DE COMPILACAO

	cd Projeto_TR1/code/source/make clean
