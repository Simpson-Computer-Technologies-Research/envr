all: output execute

output:
	gcc -o ./build/envr src/main.c src/dirs.c src/time.c

execute:
	./build/envr