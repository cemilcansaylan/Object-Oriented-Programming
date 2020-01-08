CXX = g++
CXXFLAGS = -Wall -g

main: main.o Atom.o Molecule.o Cell.o
	$(CXX) $(CXXFLAGS) -o main main.o Atom.o Molecule.o Cell.o

main.o: main.cpp Atom.h Molecule.h Cell.o
	$(CXX) $(CXXFLAGS) -c main.cpp

Atom.o: Atom.h Atom.cpp
	$(CXX) $(CXXFLAGS) -c Atom.cpp

Cell.o: Cell.h Cell.cpp
	$(CXX) $(CXXFLAGS) -c Cell.cpp

Molecule.o: Molecule.h Atom.h Cell.h Molecule.cpp
	$(CXX) $(CXXFLAGS) -c Molecule.cpp

clean:
	rm -f *.o *.x
