#include <Ball.h>

bool Ball::isSceneSet = false;
int Ball::maxX;
int Ball::maxY;

Ball::Ball(int posX, int posY)
{
this->posX=posX;
this->posY=posY;
isRightMove = true; // needed to right ball bouncing

}
Ball::~Ball()
{

}
int Ball::getX()
{
	return posX;
}
int Ball::getY()
{
	return posY;
}
void Ball::setScene(int x, int y)
{
maxX=x;
maxY=y;
isSceneSet=true;
}
void Ball::move()
{
srand(time(0));

int random = (rand() % 8) + 1;
while(isSceneSet)
{
	if(posX==0 || posX == maxX || posY == 0 || posY == maxY)
	{
	isRightMove = false;
	//TODO if ktory bedzie sprawdzal odbijanie sie kulki 'o'
	}
	while(!isRightMove)
	{
		//bool outOfLoop = false;// zmienna do while w ifie
		if(posX==0)
		{
			if(posY==0)
			{
				// 1, 5, 3 only moves ball can do
				while(!isRightMove)
				{
					random = (rand() % 8) +1;
					if(random == 3 || random == 1 || random == 5)
					{
						isRightMove = true;
						
						continue;

					}
				}
				//should i have continue here?
				continue;

			}
			if(posY==maxY)
			{
				//2,6,3
				while(!isRightMove)
				{
					random = (rand() % 8) +1;
					if(random == 2 || random == 6 || random == 3)
					{
						isRightMove = true;
						continue;
					}
				}
				continue;
			}
			//1,2, 3, 5, 6
			while(!isRightMove)
			{
				random = (rand() % 8) +1;
				if(random == 1 || random == 2 || random == 3 || random == 5 || random == 6)
				{
					isRightMove = true;
					continue;
				}
			}
			continue;
		}
		// ======================================================================== %%
		if(posX==maxX)
		{
			if(posY==0)
			{
				// 1,4,8
				while(!isRightMove)
				{
					random = (rand() % 8) +1;
					if(random == 4 || random == 1 || random == 8)
					{
						isRightMove = true;
						continue;
					}
				}
				continue;

			}
			if(posY==maxY)
			{
				//7, 2, 4 
				while(!isRightMove)
				{
					random = (rand() % 8) +1;
					if(random == 4 || random == 2 || random == 7)
					{
						isRightMove = true;
						continue;
					}
				}
				continue;

			}
			//1,2,4,7,8
			while(!isRightMove)
			{
				random = (rand() % 8) +1;
				if(random == 1 || random == 2 || random == 4 || random == 7 || random == 8)
				{
					isRightMove = true;
					continue;
				}
			}
			continue;
		}
		//-------------------------%%%%%%%%%%%%%%%--------------------------------------
		if(posY==0)
		{	
			//1,3,4,5,8
			while(!isRightMove)
			{
				random = (rand() % 8) +1;
				if(random == 1 || random == 3 || random == 4 || random == 5 || random == 8)
				{
					isRightMove = true;
					continue;
				}
			}
			continue;
		}
		if(posY==maxY)
		{
			//2.3.5.6.7
			while(!isRightMove)
			{
				random = (rand() % 8) +1;
				if(random == 12|| random == 3 || random == 5 || random == 6 || random == 7)
				{
					isRightMove = true;
					continue;
				}
			}
			continue;

		}

	}

	
	switch(random)
	{
		case 1:
			posY++;	
			break;
		case 2:
			posY--;
			break;
		case 3:
			posX++;
			break;
		case 4:
			posX--;
			break;
		case 5:
			posX++;
			posY++;
			break;
		case 6:
			posX++;
			posY--;
			break;
		case 7:
			posX--;
			posY--;
			break;
		case 8:
			posX--;
			posY++;
			break;
	}
	usleep(200000);//sleep for 0.5 sec
}
// end of method move
}
void Ball::turnOff()
{
	isSceneSet=false;
}
thread Ball::threadMove()
{
	return thread(&Ball::move, this);
}


	


