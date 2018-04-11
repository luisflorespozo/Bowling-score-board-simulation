#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>                                            /* 1 */
#include <conio.h>  /* for kbhit */                           /* 2 */
#include <dos.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int throwing_bowl(int r,int counterset, int setpoints,int strikes, int spares, int *array);

int main(int argc, char *argv[]) {
	int ball_1;
	int ball_2;
	int r;
	
	int limit=11;
	int counterset=0;
	int game_points[3];
	int strikes;
	int spares;
	int setpoints;
throwing_bowl(r, counterset,setpoints,strikes,spares,game_points);

	
	//return 0;
}

int throwing_bowl(int r,int counterset, int setpoints,int strikes, int spares, int *array)
{
	int ball_1;
	int ball_2;
	int limit=11;

	while (counterset<2)
	{
		
	printf("Throw the ball!\n");
	if (getch())
	{

	if(counterset==0){
		r=rand()%limit;
		ball_1=r;
		printf("Pins taken: %d\n",r);
		counterset++;
		setpoints=setpoints+r;
		if(ball_1==10)
		{printf("*************STRIKE*************\n");
		strikes=1;
		array[0]=strikes;
		}
	}
	if(counterset==1&&ball_1!=10)
	{
		r=rand()%(limit-ball_1-1);
		ball_2=r;
		printf("Pins taken: %d\n",r);
		counterset++;
		setpoints=setpoints+r;
		if(setpoints==10)
		{printf("***************SPARE************\n");
		spares=1;
		array[1]=spares;
		}
		
	}
	if(counterset==2)
	{
		printf("Set points: %d\n",setpoints);
		printf("----------------END OF SET---------------\n");
		array[2]=setpoints;
		setpoints=0;
		counterset=0;
		strikes=0;
		spares=0;
	}
		}
	}
}
