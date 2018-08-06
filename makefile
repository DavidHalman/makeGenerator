all: build/main build/test

build/main: build/main.o build/helpers.o
	g++ -std=c++1z -o build/main.exe build/main.o build/helpers.o  -lstdc++fs

build/test: build/test.o build/helpers_test.o build/helpers.o
	g++ -o build/test.exe build/test.o build/helpers_test.o build/helpers.o

build/main.o: src/main.cpp
	g++ -std=c++1z -o build/main.o -c src/main.cpp -lstdc++fs

build/helpers.o: src/helpers.cpp src/helpers.h
	g++ -o build/helpers.o -c src/helpers.cpp

build/test.o: tests/test.cpp tests/test.h
	g++ -o build/test.o -c tests/test.cpp

build/helpers_test.o: tests/helpers_test.cpp tests/test.h  
	g++ -o build/helpers_test.o -c tests/helpers_test.cpp

test:
	./build/test.exe

run:
	./build/main.exe sample

clean:
	rm -f *.o
