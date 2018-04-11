#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>                                           
#include <conio.h>                           
#include <dos.h> 
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 void print_date_and_time();
 int* random_bowl_spin(int *array);
 	int* print_score_table(int* game_ball_scores);
 
int main(int argc, char *argv[]) 
{
	int game_counter=0;
	int point_counter=0;
	int i=0;
	int j=0;
	print_date_and_time();
	int scores[21];
		for (j=0; j<22; j++)
		{
		scores[j]=0;
		}
			
	int set_points[2]={0,0};
	
		while (game_counter<20)
		{
			random_bowl_spin(set_points);
			for (j=0; j<2; j++)
			{
			game_counter++;
			scores[point_counter]=set_points[j];
			scores[point_counter++]=set_points[j];
			printf("\n");
			}
		printf("Frame\n");
		printf(" 1     2     3     4     5     6     7     8     9     10\n");					
		for (i=0; i<20; i++)
		{
			if (scores[i]==10)
			printf(" X ");//if STRIKE 
			if (scores[i]!=9)
			printf("%d ",scores[i]);
			if (i%2)
			printf(" /");
			
		}
		printf("\n");
		}
	print_score_table(scores);
}

 void print_date_and_time()
 {
   time_t t;
   char now[20];
   time(&t);
   strcpy(now, ctime(&t));
   printf("%s", now);
 }
 
 int* random_bowl_spin(int *array)//array contains only two numbers
{
	int ball_1;
	int ball_2;
	int random_throw;
	int setcounter=0; //index to controll only two shots are taken
	int limit_random=11;//only 10 pins can be taken down

while (setcounter<2)
{
		
	printf("Throw the ball!\n");//press any key to throw the ball
	if (getch())//if a key was pressed
	{
		if(setcounter==0)
		{
			random_throw=rand()%limit_random;//RANDOM NUMBER OF FALLEN PINS
			ball_1=random_throw;
			printf("Pins taken on 1st shot: %d\n",ball_1);
			setcounter++;
			array[0]=ball_1;
		}
		if(setcounter==1&&ball_1!=10)
		{
			random_throw=rand()%(limit_random-ball_1-1);//second ball cant be higher than 10 pins-first ball
			ball_2=random_throw;
			printf("Pins taken on 2nd shot: %d\n",ball_2);
			setcounter++;
			array[1]=ball_2;
		}
	}

}
return array;
}

//SUB FUNCTION TO print the total score----------------------------------------
	int* print_score_table(int* game_ball_scores)

	{ int j=0, sum=0, total=0;
		for (j = 0; j < 21; j++) 
		{
			sum += game_ball_scores[j];
//strike		
			if(game_ball_scores[j] == 10 && game_ball_scores[j+1] == 0 && j%2)
        	{
            	total = sum + game_ball_scores[j+2] + game_ball_scores[j+3];
       		}
//spare
	        else if ((game_ball_scores[j] + game_ball_scores[j+1]) == 10 && j%2)
	        {   
	            total = sum + game_ball_scores[j+2];
	        }
	        else
	        {
	            total = sum;
	        }
		}
	printf("Game Points TOTAL: %d\n",total);

	}
		
			
