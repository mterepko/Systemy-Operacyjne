all: project2

project2: project2.cpp ./source/Order.o
	g++ -I ./include/ ./source/Order.o project2.cpp -o project2 -lncurses -pthread
./source/Order.o: ./source/Order.cpp
	g++ -I ./include/ ./source/Order.cpp -c -o ./source/Order.o -pthread

clear:
	rm project2 ./source/Order.o