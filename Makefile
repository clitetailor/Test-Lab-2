all:
	gcc -o gen.exe generator.c -std=c99
	gcc -o main.exe heap.c -O2 -Wl,-stack,3000000
	gcc -o out.exe out.c