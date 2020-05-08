#Makefile for efficient compilation of our program

FLAGS = -pedantic-errors -std=c++11

buffer.o: buffer.cpp buffer.h
	g++ $(FLAGS) -c buffer.cpp
functionality.o: functionality.cpp func.h
	g++ $(FLAGS) -c functionality.cpp
game_show_main.o: game_show_main.cpp buffer.h func.h
	g++ $(FLAGS) -c game_show_main.cpp
gameshow: game_show_main.o functionality.o buffer.o
	g++ $(FLAGS) game_show_main.o functionality.o buffer.o -o gameshow
clean:
	rm -f gameshow game_show_main.o functionality.o buffer.o
.PHONY: clean
