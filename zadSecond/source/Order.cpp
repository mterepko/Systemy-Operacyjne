#include <Order.h>

int Order::maxX;
int Order::maxY;
bool Order::isSceneSet = false;
bool Order::empty = true;
mutex m;

Order::Order(int id)
{
	this->posX=1;
	this->posY=maxY/2;
	this->id = id;
}
Order::~Order()
{}
int Order::getPosX()
{	
	return posX;
}
int Order::getPosY()
{
	return posY;
}
string Order::getSign()
{
	return to_string(id);
}
void Order::setScene(int x, int y)
{
	maxX = x;
	maxY = y;
	isSceneSet = true;
}
void Order::move()
{
	srand(time(0));
	if(isSceneSet)

	{
		while(posX < maxX/2)
		{
			posX++;
			usleep(100000);
		}
		m.lock();
		if(empty==false)
		{
			goAround=true;
		}
		else
		{
			goAround=false;
			empty=false;
		}
		m.unlock();
		while(goAround)
		{
			while(posY>maxY/3)
			{
				posY--;
				usleep(100000);
			}
			while(posX<maxX*2/3)
			{
				posX++;
				usleep(100000);
			}
			while(posY<maxY*2/3)
			{
				posY++;
				usleep(100000);
			}
			while(posX>maxX/2)
			{
				posX--;
				usleep(100000);
			}
			while(posY>maxY/2)
			{
				posY--;
				usleep(100000);
			}
			m.lock();
			if(empty==true)
			{
				empty=false;
				goAround=false;
			}
			m.unlock();

		}
		int randTime=(rand() % 3) + 2;
		posX++;
		usleep(1000000*randTime);
		m.lock();
		empty=true;
		m.unlock();

		while(posX<maxX)
		{
			posX++;
			usleep(100000);
		}
		
	}
}
thread Order::threadMove()
{
	return thread(&Order::move, this);
}