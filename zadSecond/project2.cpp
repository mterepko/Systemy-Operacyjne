#include <ncurses.h>
#include <Order.h>
#include <vector>
#include <string>
#include <ctime>
#include <unistd.h>
#include <iostream>
using namespace std;

vector<Order> orders;
bool isProgramRunning = true;

void refreshWindow()
{
	while(isProgramRunning)
	{
		clear();
		for(int i = 0; i <orders.size();i++)
		{ 	//
			mvprintw(orders[i].getPosY(),orders[i].getPosX(),orders[i].getSign().c_str());

		}


	refresh();
	

	usleep(10000);//0.01s
	}
}
int main()
{
	int maxX, maxY;
	vector<thread> ordersThreads;
	srand(time(0));

	
	initscr();
	curs_set(0); //makes coursor invisible
	
	maxX = COLS;
	maxY = LINES;

	Order::setScene(maxX, maxY);//seting dimension of scene

	for(int i=0; i<15; i++)
	{


		Order order(i+1);
		orders.push_back(order);
		//cout << "x - \n" << order.getPosX();
	}

	//creating threads for orders
	thread refWin(refreshWindow);
	for(int i=0; i<orders.size(); i++)
	{
		ordersThreads.push_back(orders.at(i).threadMove());
		usleep(1000000);
	}
	for(int i=0; i<ordersThreads.size(); i++)
	{
		ordersThreads.at(i).join();
	}
	isProgramRunning=false;
	refWin.join();
	endwin();
return 0;
}

