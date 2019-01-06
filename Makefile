all : data/main.o data/config.o data/menu.o data/title.o data/lettre.o data/classement.o data/fenetre_de_jeu.o data/message.o data/terrain.o data/niveau.o data/tableau_brique.o data/brique.o data/balle.o data/raquette.o data/score.o data/window.o
	g++ -o main $^ -lncurses
data/main.o : data/main.cpp
	g++ -o $@ -c $<
data/config.o : data/config.cpp data/config.h
	g++ -o $@ -c $<
data/menu.o : data/menu.cpp data/menu.h
	g++ -o $@ -c $<
data/title.o : data/title.cpp data/title.h
	g++ -o $@ -c $<
data/lettre.o : data/lettre.cpp data/lettre.h
	g++ -o $@ -c $<
data/classement.o : data/classement.cpp data/classement.h
	g++ -o $@ -c $<
data/fenetre_de_jeu.o : data/fenetre_de_jeu.cpp data/fenetre_de_jeu.h
	g++ -o $@ -c $<
data/message.o : data/message.cpp data/message.h
	g++ -o $@ -c $<
data/terrain.o : data/terrain.cpp data/terrain.h
	g++ -o $@ -c $<
data/niveau.o : data/niveau.cpp data/niveau.h
	g++ -o $@ -c $<
data/tableau_brique.o : data/tableau_brique.cpp data/tableau_brique.h
	g++ -o $@ -c $<
data/brique.o : data/brique.cpp data/brique.h
	g++ -o $@ -c $<
data/balle.o : data/balle.cpp data/balle.h
	g++ -o $@ -c $<
data/raquette.o : data/raquette.cpp data/raquette.h
	g++ -o $@ -c $<
data/score.o : data/score.cpp data/score.h
	g++ -o $@ -c $<
data/window.o : data/window.cpp data/window.h
	g++ -o $@ -c $<
