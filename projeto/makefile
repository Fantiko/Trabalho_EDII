main: main.o Pesssoa.o auxiliar.o 
	gcc -o main main.o Pessoa.o

main.o: main.c Pessoa.h auxiliar.h
	gcc -c main.c

Pessoa.o: Pessoa.c Pessoa.h auxiliar.h
	gcc -c Pessoa.c

auxiliar.o: auxiliar.c auxiliar.h
	gcc -c auxiliar.c

# arquivo: arquivo.c arquivo.h
# 	gcc -c arquivo.c

clean:
	del *.o