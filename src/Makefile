block.o: block.h block.cpp
	g++ -g -c block.cpp

player.o: block.h player.h player.cpp
	g++ -g -c player.cpp

gameMap.o: block.h player.h gameMap.h gameMap.cpp
	g++ -g -c gameMap.cpp

shop.o: shop.h player.h shop.cpp
	g++ -g -c shop.cpp

io.o: block.h player.h gameMap.h io.h io.cpp
	g++ -g -c io.cpp

timer.o: timer.h timer.cpp
	g++ -g -c timer.cpp

ui.o: ui.h ui.cpp
	g++ -g -c ui.cpp -lncurses

main.o: block.h player.h gameMap.h io.h shop.h timer.h
	g++ -g -c main.cpp

main: block.o player.o gameMap.o io.o timer.o main.o ui.o shop.o
	g++ -g $^ -o $@

.PHONY: clean all
clean:
	rm *.o
	rm main

all: main
