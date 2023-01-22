all:
	gcc *.c -o test

run: all
	valgrind -s --leak-check=full  ./test 

