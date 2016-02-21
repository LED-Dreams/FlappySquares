CC=g++
LD=g++

CFLAGS=-std=c++0x -Wall

srcdir=source
VPATH=source

matsrc=../OutSystem/source

all: FlappySquares

FlappySquares: FlappySquares.o Obstacle.o Player.o LEDMatrixDraw.o LEDMatrix.o Color.o
	g++ $(CFLAGS) Color.o LEDMatrix.o LEDMatrixDraw.o Player.o Obstacle.o FlappySquares.o -o FlappySquares -lbcm2835 -lncurses

FlappySquares.o: $(srcdir)/FlappySquares.cpp $(srcdir)/FlappySquares.hpp
	g++ $(CFLAGS) -c $(srcdir)/FlappySquares.cpp

Obstacle.o: $(srcdir)/Obstacle.cpp $(srcdir)/Obstacle.hpp
	g++ $(CFLAGS) -c $(srcdir)/Obstacle.cpp

Player.o: $(srcdir)/Player.cpp $(srcdir)/Player.hpp
	g++ $(CFLAGS) -c $(srcdir)/Player.cpp

LEDMatrixDraw.o: $(matsrc)/LEDMatrixDraw.cpp $(matsrc)/LEDMatrix.hpp
	g++ $(CFLAGS) -c $(matsrc)/LEDMatrixDraw.cpp

LEDMatrix.o: $(matsrc)/LEDMatrix.cpp $(matsrc)/LEDMatrix.hpp
	g++ $(CFLAGS) -c $(matsrc)/LEDMatrix.cpp

Color.o: $(matsrc)/Color.cpp $(matsrc)/Color.hpp
	g++ $(CFLAGS) -c $(matsrc)/Color.cpp

clean:
	rm *.o
