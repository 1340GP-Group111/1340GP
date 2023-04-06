block.o: block.h block.cpp
	g++ -g -c block.cpp -o $@

player.o: block.h player.h player.cpp
	g++ -g -c player.cpp -o $@

gameMap.o: block.h player.h gameMap.h gameMap.cpp
	g++ -g -c gameMap.cpp -o $@

io.o: block.h player.h gameMap.h io.h io.cpp
	g++ -g -c io.cpp -o $@

main.o: block.h player.h gameMap.h io.h shop.h timer.h
	g++ -g -c main.cpp -o $@

main: block.o player.o gameMap.o io.o main.o
	g++ -g $^ -o $@

.PHONY: clean all
clean:
	rm *.o
	rm main

all: main
