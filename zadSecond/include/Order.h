#ifndef ORDER_H
#define ORDER_H

#include <thread>
#include <mutex>
#include <ctime>
#include <string>
#include <unistd.h>
using namespace std;

class Order
{
public:
//konstr
Order(int id);
~Order();
//destr
int getPosX();
int getPosY();
string getSign();
static bool empty;

static void setScene(int x, int y);
thread threadMove();

private:
int posX;
int posY;
bool  goAround;
int id;
static int maxX;
static int maxY;
static bool isSceneSet;
void move();


};
#endif