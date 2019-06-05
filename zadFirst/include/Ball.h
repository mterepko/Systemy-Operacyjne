#ifndef BALL_H
#define BALL_H

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <thread>
using namespace std;

class Ball
{
	public:
		static void turnOff();
		Ball(int posX,int posY); //konstr
		~Ball();//d
		int getX();
		int getY();
		static void setScene(int x, int y);
		thread threadMove();
	private:
		static bool isSceneSet;
		int posX;
		int posY;
		static int maxX;
		static int maxY;
		void move();
		bool isRightMove;



};

#endif
