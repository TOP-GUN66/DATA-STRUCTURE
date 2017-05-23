#include<stdio.h>
#include<stdlib.h>
#define Num 6
#define Infinity 10000

typedef int Graph[Num][Num];
typedef int Distance[Num][Num];

Graph G;
Distance D;

void Creat_Graph(Graph G,Distance D)
{
	int i, j;
	for(i=0;i<Num;i++)
		for (j = 0; j < Num; j++)
		{
			G[i][j] = Infinity;
		}
	for (i = 0; i < Num; i++)
		G[i][i] = 0;

	G[0][1] = 50;
	G[0][2] = 10;
	G[0][4] = 45;
	G[1][2] = 15;
	G[1][4] = 10;
	G[2][0] = 20;
	G[2][3] = 15;
	G[2][4] = 65;
	G[3][1] = 20;
	G[3][4] = 20;
	G[4][3] = 30;
	for (i = 0; i < Num; i++)
		for (j = 0; j < Num; j++)
			D[i][j] = G[i][j];
}
void Floyd(Distance D)
{
	int i, j, k, w, v;
	for (i = 0; i < Num; i++)//Ò»¹²É¨ÃèNUM´Î
	{
		for(j=0;j<Num;j++)
			for (k = 0; k < Num; k++)
				for (w = 0; w < Num; w++)
				{
					if (D[k][j] + D[j][w] < D[k][w])
						D[k][w] =D[k][j] + D[j][w];
				}
			
		
	}
}

int main(void)
{
	int i, j;
	Creat_Graph(G, D);
	Floyd(D);
	for (i = 0; i < Num; i++)
		for (j = 0; j < Num; j++)
		{
			/*if (i != j)
			{
				if (D[i][j] = Infinity)
					printf("(%d---->%d):NONE\n", i, j);
				else
					printf("(%d---->%d):%d\n", i, j, D[i][j]);
			}*/
			if(D[i][j]!=Infinity&&i!=j)
			     printf("(%d--->%d):%d\n",i,j, D[i][j]);
		}
	system("pause");
	return 0;
}