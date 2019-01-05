all : test-piece.o terrain.o window.o tableau_brique.o brique.o balle.o raquette.o config.o niveau.o tableau_niveau.o
	g++ -o main $^ -lncurses
test-piece.o : test-piece.cpp
	g++ -o $@ -c $<
terrain.o : terrain.cpp terrain.h
	g++ -o $@ -c $<
window.o : window.cpp window.h
	g++ -o $@ -c $<
tableau_brique.o : tableau_brique.cpp tableau_brique.h
	g++ -o $@ -c $<
brique.o : brique.cpp brique.h
	g++ -o $@ -c $<
balle.o : balle.cpp balle.h
	g++ -o $@ -c $<
raquette.o : raquette.cpp raquette.h
	g++ -o $@ -c $<
config.o : config.cpp config.h
	g++ -o $@ -c $<
niveau.o : niveau.cpp niveau.h
	g++ -o $@ -c $<
tableau_niveau.o : tableau_niveau.cpp  tableau_niveau.h
	g++ -o $@ -c $<

