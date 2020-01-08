CXX = g++
CXXFLAGS = -Wall -g
SOURCE = ./src

main: $(SOURCE)/main.o $(SOURCE)/Atom.o $(SOURCE)/Molecule.o $(SOURCE)/Cell.o
	$(CXX) $(CXXFLAGS) -o ./bin/main $(SOURCE)/main.o $(SOURCE)/Atom.o $(SOURCE)/Molecule.o $(SOURCE)/Cell.o

main.o: $(SOURCE)/main.cpp $(SOURCE)/Atom.h $(SOURCE)/Molecule.h $(SOURCE)/Cell.o
	cd src && $(CXX) $(CXXFLAGS) -c main.cpp

Atom: $(SOURCE)/Atom.h $(SOURCE)/Atom.cpp
	 $(CXX)$(CXXFLAGS) -c Atom.cpp

Cell.o: $(SOURCE)/Cell.h $(SOURCE)/Cell.cpp
	cd src && $(CXX) $(CXXFLAGS) -c Cell.cpp

Molecule.o: $(SOURCE)/Molecule.h $(SOURCE)/Atom.h $(SOURCE)/Cell.h $(SOURCE)/Molecule.cpp
	cd src && $(CXX) $(CXXFLAGS) -c Molecule.cpp

clean:
	rm -f *.o *.x
