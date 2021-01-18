a : main.o utils.o 
	gcc -o a main.o utils.o 
main.o : main.c auto.h
	gcc -c main.c
utils.o : utils.c auto.h
	gcc -c utils.c
clean :
	del a.exe main.o utils.o 
