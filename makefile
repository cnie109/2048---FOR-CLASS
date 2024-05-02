all: ./src/main.cpp game
	g++ -o ./bin/2048 ./src/main.cpp ./obj/game.o
game: ./src/game.cpp ./include/game.hpp
	g++ -c ./include/game.hpp ./src/game.cpp
	mv game.o ./obj
clean:
	rm ./bin/*
	rm ./obj/*
	rm ./include/game.hpp.gch

run: all
	./bin/2048
