CXX = g++
CXXFLAGS = -Wall -g
<<<<<<< HEAD
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
=======

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
>>>>>>> master

clean:
	rm -f *.o *.x
