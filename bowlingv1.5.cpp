#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>                                            /* 1 */
#include <conio.h>  /* for kbhit */                           /* 2 */
#include <dos.h> 
int* throwing_bowl(int r,int counterset, int setpoints,int strikes, int spares, int *array);
int* print_score_table(int ball1,int ball2,int strikes, int spares,int gamecounter, int* scores);
int main(int argc, char *argv[]) {
	int ball_1;
	int ball_2;
	int r;
	int j;
	int sum=0;
	//int total=0;
	int gamepoints;
	int limit=11;
	int counterset=0;
	int countergame=0;
	int game_points[5]={0,0,0,0,0};
	int strikes=0;
	int spares=0;
	int setpoints;
	int game_number[10];
	int game_ball_scores[20];
	for (j=0; j<21; j++)
    {game_ball_scores[j]=0;}

while (1)
{
	//call to function throw ball
throwing_bowl(r, counterset,setpoints,strikes,spares,game_points);
	//evaluate the game
	//game points [#throw, counterset, setpoints, strikes, spares]
	switch (game_points[0])
	{
	case 0:
		switch (game_points[1])
		{
		case 0:
			counterset=0;
			ball_1=game_points[2];
			ball_2=game_points[3];
			break;
		case 1://spare
			spares=1;
			counterset=0;
			ball_1=game_points[2];
			ball_2=game_points[3];
			break;
		}
		break;	
	case 1://strike
		strikes=1;
		counterset=0;
		ball_1=game_points[2];
		ball_2=game_points[3];
		break;
	}
	//when the game is over, calculate points
	if(countergame==20)
	{
		for (j = 0; j < 21; j++) 
		{
	   	 	sum += game_ball_scores[j];
	 	}
	printf("Game Points TOTAL: %d\n",sum);
	break;
	}
	// trying to calculate spare and strike scores
/*	if(countergame==20)
	{
		for (j = 0; j < 21; j++) 
		{
			sum += game_ball_scores[j];
//strike		
			if(game_ball_scores[j] == 10 && game_ball_scores[j+1] == 0)
        	{
            	total = sum + game_ball_scores[j+2] + game_ball_scores[j+3];
       		}
//spare
	        else if ((game_ball_scores[j] + game_ball_scores[j+1]) == 10)
	        {   
	            total = sum + game_ball_scores[j+2];
	        }
	        else
	        {
	            total = sum;
	        }
		}
	printf("Game Points TOTAL: %d\n",total);
	break;
	}*/
	//else, keep updating the score table
	print_score_table(ball_1, ball_2,strikes, spares,countergame, game_ball_scores);
	countergame=countergame+2;
	strikes=0;
	spares=0;


	
}

}
	//SUB FUNCTION TO print the SCORE TABLE----------------------------------------
	int* print_score_table(int ball1,int ball2,int strikes, int spares,int gamecounter,int* scores)
	{
		int j;
		int game_number[10];
		for (j=1; j<11; j++)
	    {game_number[j]=j;}
	    printf("Game: ");
		    for (j=1; j<11; j++)
			{
			printf(" %d  /",game_number[j]);
			}
		printf("\n");
		if (strikes==1)
		{
		scores[gamecounter]=10;
			scores[gamecounter+1]=0;
		}
		if (spares==1)
		{
		scores[gamecounter]=0;
		scores[gamecounter+1]=10;
		}
		if (strikes!=1&& spares!=1)
		{
		scores[gamecounter]=ball1;
		scores[gamecounter+1]=ball2;
		}
	   printf("Scor: ");
		   for (j=0; j<21;  j++)
			{
			printf("%d ",scores[j]);
				if (j%2)
				{printf("/");
				}
			}
	printf("\n");

	return scores;
}
//SUB FUNCTION TO THROW BALL----------------------------------------
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
			r=rand()%limit;//RANDOM NUMBER OF FALLEN PINS
			ball_1=r;
			printf("Pins taken 1st shot: %d\n",r);
			counterset++;
			setpoints=setpoints+r;
			array[2]=ball_1;
			if(r==10)
			{
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
			printf("Pins taken 2nd shot: %d\n",r);
			counterset++;
			setpoints=setpoints+r;
			array[3]=ball_2;
			if(setpoints==10)
			{printf("***************SPARE************\n");
			spares=1;
			array[1]=spares;
			}
		}
		if(counterset==2)
		{
			printf("----------------END OF SET---------------\n");
			array[4]=setpoints;
			setpoints=0;
		}
	}
	}
	strikes=0;
	spares=0;
	return array;
}
