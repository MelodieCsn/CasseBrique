all : test-piece.o fenetre_de_jeu.o menu.o title.o lettre.o message.o terrain.o niveau.o score.o window.o tableau_brique.o brique.o balle.o raquette.o
	g++ -o main $^ -lncurses
test-piece.o : test-piece.cpp
	g++ -o $@ -c $<
fenetre_de_jeu.o : fenetre_de_jeu.cpp fenetre_de_jeu.h
	g++ -o $@ -c $<
menu.o : menu.cpp menu.h
	g++ -o $@ -c $<
title.o : title.cpp title.h
	g++ -o $@ -c $<
lettre.o : lettre.cpp lettre.h
	g++ -o $@ -c $<
message.o : message.cpp message.h
	g++ -o $@ -c $<
terrain.o : terrain.cpp terrain.h
	g++ -o $@ -c $<
niveau.o : niveau.cpp niveau.h
	g++ -o $@ -c $<
score.o : score.cpp score.h
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
