all: project

project: project.cpp ./source/Ball.o
	g++ -I ./include/ ./source/Ball.o project.cpp -o project -lncurses -pthread
./source/Ball.o: ./source/Ball.cpp
	g++ -I ./include/ ./source/Ball.cpp -c -o ./source/Ball.o -pthread

clear:
	rm project ./source/Ball.o
