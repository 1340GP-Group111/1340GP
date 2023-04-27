CXXFLAGS = -g -std=c++11

block.o: block.h block.cpp
	g++ $(CXXFLAGS) -c block.cpp

player.o: block.h player.h player.cpp
	g++ $(CXXFLAGS) -c player.cpp

gameMap.o: block.h player.h gameMap.h gameMap.cpp
	g++ $(CXXFLAGS) -c gameMap.cpp

shop.o: shop.h player.h shop.cpp block.h
	g++ $(CXXFLAGS) -c shop.cpp

io.o: block.h player.h gameMap.h io.h io.cpp
	g++ $(CXXFLAGS) -c io.cpp

#timer.o: timer.h timer.cpp
	#g++ $(CXXFLAGS) -c timer.cpp

#ui.o: ui.h ui.cpp
	#g++ $(CXXFLAGS) -c ui.cpp -lncurses

main.o: block.h player.h gameMap.h io.h shop.h #timer.h
	g++ $(CXXFLAGS) -c main.cpp

main: block.o player.o gameMap.o io.o  main.o shop.o #ui.o timer.o
	g++ $(CXXFLAGS) $^ -o $@

.PHONY: clean all
clean:
	rm *.o
	rm main
	rm *.gch

all: main