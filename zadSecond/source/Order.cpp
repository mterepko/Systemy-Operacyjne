#include <Order.h>

int Order::maxX;
int Order::maxY;
bool Order::isSceneSet = false;
bool Order::empty = true;
int Order::count = 0;
bool Order::synchro = false;
mutex m;
mutex mu;
condition_variable cond;


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
			first = false;
			ready = true;
			count++;
		}
		else
		{
			first = true;
			ready = false;
			empty=false;
		}
		m.unlock();
		

		for(int i=0; i < count; i++)
		{
			posY++;
		}

		while(ready)
		{
			unique_lock<mutex> lck(mu);
			cond.wait(lck);
			ready = false;

		}

		if(first == true)
		{
			int randTime=(rand() % 3) + 2;
		
			
			usleep(1000000*randTime);
			unique_lock<mutex> lck(mu);
			
			cond.notify_all();

			m.lock();
			empty=true;
			count = 0;

			m.unlock();
		}

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