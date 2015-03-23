CXX=g++
CXXFLAGS=-W -Wall
LDFLAGS=
EXEC=tictactoe

all: $(EXEC)

tictactoe: Game.o Ia.o Referee.o
	$(CXX) -o tictactoe Game.o Ia.o Referee.o main.cpp $(CXXFLAGS)

Game.o: Game.cpp
	$(CXX) -o Game.o -c Game.cpp $(CXXFLAGS)

Ia.o: Ia.cpp
	$(CXX) -o Ia.o -c Ia.cpp $(CXXFLAGS)

Referee.o: Referee.cpp
	$(CXX) -o Referee.o -c Referee.cpp $(CXXFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
