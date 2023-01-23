all:
	gcc *.c -o test

run: all
	valgrind --show-leak-kinds=all -s --leak-check=full  ./test 

