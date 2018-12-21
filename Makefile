all : classement.o score.o joueur.o
	g++ -o main $^ -lncurses
classement.o : classement.cpp
	g++ -o $@ -c $<
score.o : score.cpp
	g++ -o $@ -c $<
joueur.o : joueur.cpp
	g++ -o $@ -c $<
