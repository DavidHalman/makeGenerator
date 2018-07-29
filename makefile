build/main: build/main.o build/helpers.o
	g++ -std=c++1z -o build/main.exe build/main.o build/helpers.o  -lstdc++fs

build/main.o: src/main.cpp
	g++ -std=c++1z -o build/main.o -c src/main.cpp -lstdc++fs

build/helpers.o: src/helpers.cpp src/helpers.h
	g++ -o build/helpers.o -c src/helpers.cpp

test:
	./build/main.exe tests

clean:
	rm -f *.o
