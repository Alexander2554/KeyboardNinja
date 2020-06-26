all: KeyNin
KeyNin:	Main.o
	g++ -std=c++11 -Wall -Werror build/src/Main.o -o bin/KeyNin
	./bin/KeyNin
Main.o:
	g++ -std=c++11 -Wall -Werror -c src/Main.cpp -o build/src/Main.o
clean:
	rm -rf build/src/*.o bin/KeyNin