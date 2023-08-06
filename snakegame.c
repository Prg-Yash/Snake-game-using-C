#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h> 
int height = 40, width = 20;									  // height=x width=y or iterations
int x, y, score = 0, foodX, foodY, Gameover, flag, countTail = 0; // x and y are for snake positioning and foodX and foodY are co-ordinates of food
int tailX[100], tailY[100];
void setup();
void draw();
void input();
void logic();
int main()
{
	system("color 30");  //used for changing bg color and text color 3 is for  bg color and 0 is for text
	char save;

	int d, l;
	char str[20];
	char difficulty;
	do
	{ 
		
	     countTail=0;
		 printf("\nWarning! Don't press snake control keys on keyboard for a long time\n");
		 printf("\nUse 'WASD' keys to move the snake\n");
		printf("\nPlease Choose your difficulty\n Press h for hard\n Press n for normal \n Press e for easy\n");
		scanf("%c", &difficulty);
		
	     setup();
	     flag=0;  //To reset the input 
		 score=0; //To reset the score
		while (!Gameover)
		{
         
			switch (difficulty)
			{
			case 'h':
				Sleep(3);
				break;
			case 'n':
				Sleep(30);
				break;
			case 'e':
				Sleep(50);
				break;
			}
			
			draw();
			input();
			logic();
		}

		printf("GAMEOVER!\n");
		if(save!='y'){

			getch();  //Below string will appear when we hit something on keypad;

		printf("\nPLEASE ENTER YOUR FIRST NAME :");
		scanf("%s", str);
		}
		fflush(stdin);  //It is use to flush/remove the enter key input.
		printf("\nHELLO MR/MRS %s YOUR SCORE IS %d \n DO YOU WANT TO RETRY?(y/n)\n", str, score);
		scanf("%c", &save);
		fflush(stdin); 
		system("cls"); 
		
		
	} while(save != 'n');
	printf("THANK YOU FOR PLAYING :)");
	return 0;
}
void setup()
{
	Gameover = 0;
	x = height / 2;
	y = width / 2;

label1:
	foodX = rand() % 40; // If foodx generates 0 then it will be on border therefore>
	if (foodX == 0)

		goto label1;

label2:
	foodY = rand() % 20; // If foodx generates 0 then it will be on border therefore>
	if (foodY == 0)

		goto label2;
}
void draw()
{
	int i, j, k, ch = 0;
	system("cls");
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
		{
			if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
				printf("[]");

			else
			{
				if (i == y && j == x)
				{
					printf("O ");
				}
				else if (i == foodY && j == foodX)
					printf("F ");

				else
				{
					int check = 0;
					for (k = 0; k < countTail; k++)
					{
						if (i == tailY[k] && j == tailX[k])
						{
							printf("o ");
							check = 1;
						}
					}
					if (check == 0)
						printf("  ");
				}
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("Your Score is %d\n", score);
}

void input()
{
	if (kbhit())
	{

		switch (getch())
		{
		case 'w':
			flag = 1;
			break;
		case 'a':
			flag = 2;
			break;
		case 's':
			flag = 3;
			break;
		case 'd':
			flag = 4;
			break;
		case 'q':
			Gameover = 1;
			break;
		}
	}
}
void logic()
{
       int i,k;
	// If head touch the body
	for ( k = 0; k < countTail; k++)
	{
		if (x == tailX[k] && y == tailY[k])
		{
			Gameover = 1;
			printf("\nYou touched your body\n");
		}
	}
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2x, prev2y;

	tailX[0] = x;
	tailY[0] = y;

	for (i = 1; i < countTail; i++)
	{  
		prev2x = tailX[i];
		prev2y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2x;
		prevY = prev2y;
	}

	switch (flag)
	{
	case 1:
		y--;
		break;
	case 2:
		x--;
		break;
	case 3:
		y++;
		break;
	case 4:
		x++;
		break;
	default:
		break;
	}

	if (x == 0 || x == height || y == 0 || y == width)
	{
		Gameover = 1;
	}

	if (x == foodX && y == foodY)
	{	label3:
		foodX = rand() % 40; // If foodx generates 0 then it will be on border therefore;
		if (foodX == 0)
			goto label3;

	label4:
		foodY = rand() % 20; // If foodx generates 0 then it will be on border therefore;
		if (foodY == 0)
			goto label4;

     	score += 10;
		countTail++;
	}
}
