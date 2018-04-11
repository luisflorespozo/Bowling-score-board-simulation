#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>                                            /* 1 */
#include <conio.h>  /* for kbhit */                           /* 2 */
#include <dos.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int* throwing_bowl(int r,int counterset, int setpoints,int strikes, int spares, int *array);

int main(int argc, char *argv[]) {
	int ball_1;
	int ball_2;
	int r;
	int gamepoints;
	int limit=11;
	int counterset=0;
	int game_points[3]={0,0,0};
	int strikes=0;
	int spares=0;
	int setpoints;
while (1)
{

throwing_bowl(r, counterset,setpoints,strikes,spares,game_points);

	switch (game_points[0])
	{
	case 0:
		switch (game_points[1])
		{
		
		case 0:
			gamepoints=gamepoints+game_points[2];
			printf("Game Points: %d\n",gamepoints);
			counterset=0;
			break;
		case 1://spare
		printf("entre:\n");
			gamepoints=gamepoints+10;
			printf("Game Points spare: %d\n",gamepoints);
			spares=0;
			counterset=0;
			break;
		}
		break;	
	case 1://strike
		gamepoints=gamepoints+game_points[2]+10;
		printf("Game Points strike: %d\n",gamepoints);
		strikes=0;
		counterset=0;
		break;
	}
	//return 0;
}
}

int* throwing_bowl(int r,int counterset, int setpoints,int strikes, int spares, int *array)
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
			if(r==10)
			{printf("*i got in\n");
			printf("*************STRIKE*************\n");
			strikes=1;
			array[0]=strikes;
			counterset=2;
			array[2]=setpoints;
			
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
			strikes=0;
			spares=0;
		}
	}
	}
	
	return array;
}
