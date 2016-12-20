#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>

#define UPARR 72 
#define LEFTARR 75 
#define DOWNARR 80 
#define RIGHTARR 77 

void randposition(int *,int *);                //generates random position for food

int erfg(int g);                                    //function to calculate score
//time_t timer;

main()
{
	srand(time(0));
	
	int i=11,k,j,m,n,turn=0,checker,force=0,bite=0;         
	int counter=0,score=0,time=0;
	
	char a[i][i],input,direction='?';
	
	
	for(j=0;j<=i-1;j++)                              //empty background
	{
		for(k=0;k<=i-1;k++)
		{
			a[j][k]=' ';
		}
	}
	int lol=0;
	clock_t start_t, end_t ,partend_t ,partstart_t , total_t;     //initializing clock variables
	
	int pos_x=i/2;
	int pos_y=i/2;
	a[pos_x][pos_y]=219;                       //make head with ascii 232
	do
	randposition(&m,&n);                          //random coordinates for food
	while(m==pos_x&&n==pos_y);
	a[m][n]='O';                  
	int z,w;

printf(" ----------------------\n");
	for(j=0;j<=i-1;j++)                            //initial display of user and food
		{
			printf("|");
			for(k=0;k<=i-1;k++)
			{
				printf("%c ",a[j][k]);
			}
			printf("|");
			if(j==10)
			printf("\n ----------------------\n");
			else
			printf("\n|                      |\n");
		}
	
		
		printf("Your Score:0\n\n");                   //display score after a  successful capture
	printf("press arrow keys to collect food(O) \n\n");
	printf("Press spacebar key to start the game\n");
	a[m][n]=' ';
	while(getch()!=32)
	;
	char *head, *tail, *arr[1000], *kill;
	int dump=0,dump2=0;
//-------------------------------------------------------------------------------------------------------------------------------------	
for(z=1;;z++)                                      //program execution begins
{
	if(bite==1)
	break;
	if(turn==1)
	{
	do
	randposition(&m,&n);                          //random coordinates for food
	while(m==pos_x&&n==pos_y);
	a[m][n]='O';
	 a[pos_x][pos_y]=219;
	}
	else if(turn==0)
	{
		head=&a[pos_x][pos_y];
	 	tail=head;
	}
	

		start_t=clock();                                     //starting the clock
		partstart_t=clock();                                 //starting a partial clock/timer
		for(w=1;;w++)
		{
			if(bite==1)
			break;
			while(!kbhit())
			{
				
				
				partend_t=clock();
				
				
				if(partend_t-partstart_t==1)
				{
					arr[dump]=head;
					tail=arr[dump2];
					dump++;
					
					if(direction=='?')
					{
						;
					}
					else if(direction=='u')
					{
						if(pos_x!=0)
						pos_x--;                                        //pos_x is vertical & pos_y is horizontal
						else
						pos_x=10;
					}
					else if(direction=='d')
					{
						if(pos_x!=10)
						pos_x++;
						else
						pos_x=0;
					}
					else if(direction=='l')
					{
						if(pos_y!=0)
						pos_y--; 
						else
						pos_y=10;
					}
					else if(direction=='r')
					{
						if(pos_y!=10)
						pos_y++;
						else
						pos_y=0;
					}
					head=&a[pos_x][pos_y];
					
					if(pos_x==m&&pos_y==n)
					{
						score=score+10+erfg(15-partend_t);
						lol=1;
						LABEL1:randposition(&m,&n);
						kill=&a[m][n];
						for(checker=dump2;checker<=dump;checker++)
						{
							if(kill==arr[checker])
							force=1;
							if(force==1)
							{
								goto LABEL1;
							}
						}
					}
					
					else
					{
					dump2++;
					
					for(checker=dump2;checker<=dump;checker++)                        //bite function
					{
						if(arr[checker]==head&&turn==1)
						{
							bite=1;
							break;
						}
					}
					}
					if(bite==1)
					break;
					system("cls");
					printf(" ----------------------\n");
					a[m][n]='O';
					*head=219;
					*tail=' ';
					if(turn==0)
					a[i/2][i/2]=219;
					turn=1;
					for(j=0;j<=i-1;j++)                            //initial display of user and food
					{
			
						printf("|");
						
						for(k=0;k<=i-1;k++)
						{
							printf("%c ",a[j][k]);
						}
						printf("|");
						if(j==10)
						printf("\n ----------------------\n");
						else
						printf("\n|                      |\n");
					}
	
		
					printf("Your Score:%d\n\n",score);                   
				
				if(pos_x==m&&pos_y==n)
				{
					end_t=clock();
					total_t=(1.0*(end_t-start_t))/(1.0*CLOCKS_PER_SEC);
					time=total_t;
					score=score+ 10+erfg(5-total_t);                   //score increment formula
					turn=1;
					break;
				}
				if(bite==1)
				break;
				Sleep(200);                                         //Sleep
				}
				
				partstart_t=clock();
				if(bite==1)
				break;
			}
			if(bite==1)
				break;
			if(kbhit())
			{
				if(bite==1)
				break;
				input=getch();
				
			if(input==UPARR)
			{
				if(direction=='d'||direction=='u')
				;
				else
				direction='u';
			}
			else if(input==DOWNARR)
			{
				if(direction=='u'||direction=='d')
				;
				else
				direction='d';
			}
			else if(input==LEFTARR)
			{
				if(direction=='r'||direction=='l')
				;
				else
				direction='l';
			}
			else if(input==RIGHTARR)
			{
				if(direction=='l'||direction=='r')
				;
				else
				direction='r';
			}
			}
		
			if(bite==1)
			break;
		}
		
		
				if(bite==1)
				break;	
}
	printf("\n\nGAME OVER, YOUR SNAKE BIT ITSLEF");
	return 0;
}

void randposition(int *x,int *y)                   //generate random position for food between (0-10,0-10)
{
	*x=rand()%11;
	*y=rand()%11;
}

int erfg(int g)
{
	if (g<0)
	return 0;
	else
	return g;
}
