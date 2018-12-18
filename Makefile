all : test-piece.o window.o balle.o
	g++ -o main $^ -lncurses
test-piece.o : test-piece.cpp
	g++ -o $@ -c $<
window.o : window.cpp window.h
	g++ -o $@ -c $<
balle.o : balle.cpp balle.h
	g++ -o $@ -c $<
