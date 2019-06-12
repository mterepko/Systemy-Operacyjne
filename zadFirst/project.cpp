#include <ncurses.h>
#include <thread>
#include <unistd.h>
#include  <vector>
#include <cstdlib>
#include <ctime>
#include <Ball.h>
using namespace std;

vector<Ball> balls;
bool isProgramRunning = true;
int delayPrint = 0; // variable helpoing to draw ball after 5 sec
//function to refresh and print out Balls "o"
void refreshWindow()
{	

	while(isProgramRunning)
	{
		clear();
		for(int i = 0; i <delayPrint;i++)
		{
			mvprintw(balls[i].getY(),balls[i].getX(),"o");
		}


	refresh();
	

	usleep(10000);//0.01s
	}

}
void endWindow()
{
int ch = getch();
	if(ch == 120 || ch == 88)
	{
		
		isProgramRunning = false;
	}

}
int main()
{
	int maxX, maxY, posX, posY;
	vector<thread> ballsMoving;
	srand(time(0));

	
	initscr();
	curs_set(0); //makes coursor invisible
	
	keypad(stdscr, TRUE);
	maxX = COLS;
	maxY = LINES;
	//we are getting dimensions of the window
	//mvprintw(LINES, COLS, "%d", maxX);
	Ball::setScene(maxX, maxY);

	
	
	//setting position of start for balls
	for(int i = 0; i< 10; i++)
	{
		posX = rand() % maxX;
		posY = rand() % maxY;
		Ball ball(posX, posY);
		balls.push_back(ball);

		
	//5 sec
	
	}
	thread refWindow(refreshWindow);
	thread endWind(endWindow);
	
		for(int i = 0; i<balls.size();i++)
		{		
			delayPrint++;
			ballsMoving.push_back(balls.at(i).threadMove());
			usleep(2000000);// 2 sec
		}
		
	//int ch = getch(); //variable to get 'x' presing x exits program
	if(isProgramRunning == false)
	{
	
		Ball::turnOff();//function taht stops balls movement
		for(int i = 0; i<balls.size();i++)
		{
			ballsMoving.at(i).join();
	
		}
	}
	usleep(2000000);
	endWind.join();
	refWindow.join();
	endwin();
	


	return 0;
}