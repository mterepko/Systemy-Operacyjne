#ifndef BALL_H
#define BALL_H

#include <thread>
#include <mutex>
#include <time.h>
using namespace std;

class Order
{
public:
//konstr
Order(int posX, int posY);
~Order();
//destr
int getPosX();
int getPosY();
static void setScene(int x, int y);
thread threadMove();

private:
int posX;
int posY;
static int maxX;
static int maxY;
void move();


};
#endif