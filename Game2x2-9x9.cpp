#include <iostream>
#include <stdlib.h>
#include <ctime>
void MixingMas(int **GameMas,int N)
{
	srand(time(NULL));
	bool check;
	int GenMas[N*N];
 	for(int i=0;i<N*N-1;)
 	{
 		check=false;
 		int RandNum=1+rand()%(N*N-1);
 		for(int j=0;j<i;j++)
 		{
 			if(GenMas[j]==RandNum)
			{
				check=true;
				break;
			}
		}
		if(!check)
		{
			GenMas[i]=RandNum;
			i++;
		}
	}

	int CheckNum;
	int Correct=0;
	for(int i=0;i<N*N-2;i++)
	{
		CheckNum=GenMas[i];
		for(int j=0;j<N*N-1;j++)
		{
			if(CheckNum>GenMas[j])
			{
				Correct++;
			}
		}
	}
	if(Correct % 2==1)
	{
		int num =GenMas[N*N-3];
		GenMas[N*N-3]=GenMas[N*N-2];
		GenMas[N*N-2]=num;
	}
	
	
	

	int a =0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			GameMas[i][j]=GenMas[a];
			a++;
			if(a==N*N)
			{
				GameMas[i][j]=0;
			}
		}
	}
}
void SlideNum(int **GameMas,int N)
{
	int x,y;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(GameMas[i][j]==0)
			{
				x=j;
				y=i;
			}
		}
	}
	char simbol=getchar();
	system("cls");
	switch(simbol)
	{
		case 'w':
			{
				if(y!=0)
				{
					int n=GameMas[y][x];
					GameMas[y][x]=GameMas[y-1][x];
					GameMas[y-1][x]=n;
				}
				break;
			}
		case 's':
			{
				if(y!=N-1)
				{
					int n=GameMas[y][x];
					GameMas[y][x]=GameMas[y+1][x];
					GameMas[y+1][x]=n;	
				}
				break;
			}
		case 'a':
			{
				if(x!=0)
				{
					int n=GameMas[y][x];
					GameMas[y][x]=GameMas[y][x-1];
					GameMas[y][x-1]=n;
				}
				break;
			}
		case 'd':
			{
				if(x!=N-1)
				{
					int n=GameMas[y][x];
					GameMas[y][x]=GameMas[y][x+1];
					GameMas[y][x+1]=n;
				}
				break;
			}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			std::cout<<GameMas[i][j]<<"\t";
		}
		std::cout<<"\n";
	}
}
void CheckWin(int **mask,int **GameMas,int N)
{
	bool Win=false;
	for(int i =0;i<N;i++)
	{
		for(int j =0;j<N;j++)
		{
			if(mask[i][j]==GameMas[i][j])
			{
				Win=true;
			}
			else if(mask[i][j]!=GameMas[i][j])
			{
				Win=false;
				i=N;
				break;
			}
		}
	}
	if(Win==false)
	{	SlideNum(GameMas,N);
		CheckWin(mask,GameMas,N);
	}else std::cout<<"You WIN";
}
int main() 
{
	int N;
	std::cout<<"Write size game 2x2 - 9x9: ";
	std::cin>>N;
	int **mask;
	int **GameMas;
	mask = (int**)malloc( N * sizeof( int* ) + N*N*sizeof( int ) );
	GameMas = (int**)malloc(N*sizeof(int*)+ N*N*sizeof(int));
	mask[0]= (int*)(mask+N);
	GameMas[0] = (int*)(GameMas+N); 
	for(int i =0; i<N; i++)
	{
       mask[i] = mask[0] + i * N;
	   GameMas[i] = GameMas[0] + i * N; 
	}
	for(int i=0;i<N;i++)
	{
		int a;
		for(int j=0;j<N;j++)
		{
			
			mask[i][j] = 1+a++;
			if(i==N-1&&j==N-1) mask[i][j]=0;	
		}
	}
	MixingMas(GameMas,N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			std::cout<<GameMas[i][j]<<"\t";
		}
		std::cout<<"\n";
	}
	CheckWin(mask,GameMas,N);
	free(mask);
	return 0;
}

