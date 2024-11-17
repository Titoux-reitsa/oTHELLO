ti = -Wall -Wextra 

main : main.o fonctions_bases.o IA.o test.o
	gcc $^ -o $@ $(ti)

main.o : main.c
	gcc -c $^ -o $@ $(ti)

fonctions_bases.o : fonctions_bases.c fonctions.h
	gcc -c $< -o $@ $(ti)

test.o : test.c test.h fonctions.h
	gcc -c $< -o $@ $(ti)

IA.o : IA.c fonctions.h
	gcc -c $< -o $@ $(ti)

clean :
	rm -f main *.o

tar : 
	tar -cf projet.tar *.c *.h Makefile