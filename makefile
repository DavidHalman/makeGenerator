build/main: build/main.o
	g++ -std=c++1z -o build/main.exe build/main.o -lstdc++fs

build/main.o: src/main.cpp
	g++ -std=c++1z -o build/main.o -c src/main.cpp -lstdc++fs

test:
	./build/main.exe tests

clean:
	rm -f *.o
