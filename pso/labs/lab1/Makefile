.PHONY: clean
.SILENT:
clean:
	@rm *.o main

main: main.o func.o
	gcc main.o func.o -o main

func.o: func.c func.h
	gcc -c func.c -o func.o

main.o: main.c func.h
	gcc -c main.c -o main.o

create_static: add.o sub.o
	ar rc libmymath.a add.o sub.o
	gcc -static demo.c -o demo_static -L . -lmymath

create_static_functions: add.c sub.c
	gcc -c add.c sub.c

create_dynamic: add_shared.o sub_shared.o
	gcc -shared add_shared.o sub_shared.o -o libmymath.so
	gcc demo.c -o demo_shared -lmymath -L .

create_dynamic_functions: add.c sub.c
	gcc -fPIC -c add.c -o add_shared.o
	gcc -fPIC -c sub.c -o sub_shared.o

clean_extra:
	LD_PRELOAD=
	rm mymalloc.so malloc.o main
	
dynamic_extra:
	gcc -Wall -fPIC -shared malloc.c -o mymalloc.so
	export LD_PRELOAD=./mymalloc.so
	gcc main.c -o main
	LD_PRELOAD=./mymalloc.so ./main
	LD_PRELOAD=
	
run:
	./demo_shared
	./main
