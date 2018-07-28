main: main.o
	g++ -std=c++1z -o main main.o -lstdc++fs

main.o: main.cpp
	g++ -std=c++1z -c main.cpp -lstdc++fs
