#include<stdio.h>
#include<stdlib.h>
#define VEXNUM 6
#define Infinity 10000

typedef int Graph[VEXNUM][VEXNUM];
typedef int Status[VEXNUM];
typedef int Distance[VEXNUM - 1];
typedef int Path[VEXNUM - 1][VEXNUM - 1];
Graph G;
Distance D;
Status S;
Path P;

void Creat_Graph(Graph G)
{
	int i,j;
	for (i = 0; i < VEXNUM; i++)
		for (j = 0; j < VEXNUM; j++)
			G[i][j] = Infinity;

	G[0][1] = 50;
	G[0][2] = 10;
	G[1][2] = 15;
	G[1][4] = 10;
	G[2][3] = 15;
	G[3][1] = 20;
	G[3][4] = 20;
	G[3][5] = 3;
	G[4][3] = 30;
	G[0][4] = 45;
	G[2][0] = 20;
}
void Init_Distance(Distance D,Status S ,Path P,Graph G,int start)
{
	int i,j;
	for (i = 0; i < VEXNUM; i++)
	{
		S[i] = 0;
		D[i] = G[start][i];
		for (j = 0; j < VEXNUM-1; j++)
			P[i][j] = 0;
		if (D[i] < Infinity)
		{
			P[i][start] = 1;
			P[i][i] = 1;
		}

	}

}
void Dijkstra(Distance D, Status S, Path P, Graph G, int start)
{
	int i, k, v,min;
	for (i = 0; i < VEXNUM; i++)
	{
		min = Infinity;
		for(k=0;k<VEXNUM;k++)
			if(!S[k])
				if (D[k] < min)
				{
					v=k;
					min = D[k];
				}
		S[v] = 1;
		if(v!=start)
             printf("--->%d=%d\n", v, min);
		for (k = 0; k < VEXNUM; k++)
		{
			if (!S[k] && (min + G[v][k]) < D[k])
			{
				D[k] = min + G[v][k];
				

			}
		}
		
	}
}

int main(void)
{
	int i,j;
	int start = 0;
	Creat_Graph(G);
	Init_Distance(D, S, P, G, start);
	Dijkstra(D, S, P, G, start);
	system("pause");
	return 0;
}
