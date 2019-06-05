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
			mvprintw(balls[i].getX(),balls[i].getY(),"o");
		}


	refresh();

	usleep(10000);//0.05s
	}

}
int main()
{
	int maxX, maxY, posX, posY;
	vector<thread> ballsMoving;
	srand(time(0));

	
	initscr();
	curs_set(0); //makes coursor invisible
	

	maxX = LINES;
	maxY = COLS;
	//we are getting dimensions of the window
	//mvprintw(LINES, COLS, "%d", maxX);
	Ball::setScene(maxX, maxY);

	
	
	//setting position of start for balls
	for(int i = 0; i< 3; i++)
	{
		posX = rand() % maxX;
		posY = rand() % maxY;
		Ball ball(posX, posY);
		balls.push_back(ball);

		
	//5 sec
	
	}
	thread refWindow(refreshWindow);
	for(int i = 0; i<balls.size();i++)
	{	
		delayPrint++;
		ballsMoving.push_back(balls.at(i).threadMove());
		usleep(5000000);
	}
	int ch = getch(); //variable to get 'x' presing x exits program
	if(ch == KEY_LEFT)
	{
		Ball::turnOff();
		for(int i = 0; i<balls.size();i++)
		{
			ballsMoving.at(i).join();
	
		}
	
	refWindow.join();
	endwin();
	}


	return 0;
}