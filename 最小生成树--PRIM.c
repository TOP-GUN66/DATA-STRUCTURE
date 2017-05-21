#include<stdio.h>
#include<stdlib.h>
#define n 6
#define Infinity 10000
typedef int Adjmatrix[n][n];
typedef struct {
	int from, to;
	int length;
}TreeedgeNode;
typedef TreeedgeNode MST[n - 1];
Adjmatrix G;
MST T;
void Creat_Graph(Adjmatrix G)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			G[i][j] = Infinity;
	G[1][0] = 1;
	G[0][1] = 1;

	G[0][3] = 3;
	G[3][0] = 3;

	G[0][2] = 4;
	G[2][0] = 4;

	G[1][3] = 2;
	G[3][1] = 2;

	G[2][5] = 5;
	G[5][2] = 5;

	G[2][4] = 7;
	G[4][2] = 7;

	G[3][4] = 6;
	G[4][3] = 6;

	G[3][5] = 4;
	G[5][3] = 4;

	G[4][5] = 8;
	G[5][4] = 8;


}

void Init_Candidates(Adjmatrix G, MST T, int r)
{
	int i = 0;
	int k = 0;
	for(i=0;i<n;i++)
		if (i != r)
		{
			T[k].from = r;
			T[k].to = i;
			T[k].length = G[r][i];
			k++;
		}
	
}
int Select_Lightedge(MST T, int k)
{
	int i = Infinity;
	int j, minpose;
	minpose = 0;
	for (j = k; j < n - 1; j++)
	{
		if (T[j].length < i)
		{
			i = T[j].length;
			minpose = j;
		}
	}
	
	return minpose;
}
void Adjust_Candidates(Adjmatrix G, MST T, int k, int v)
{
	int i, d;
	for (i = k; i < n - 1; i++)
	{
		d = G[v][T[i].to];
		if (d < T[i].length)
		{
			T[i].length = d;
			T[i].from = v;
		}
	}
}
void PrimMST(Adjmatrix G, MST T, int r)
{
	int k, m, v;
	TreeedgeNode e;
	Init_Candidates(G, T, r);
	for (k = 0; k < n - 1; k++)
	{
		m = Select_Lightedge(T, k);
		e = T[m];
		T[m] = T[k];
		T[k] =e;
		v = T[k].to;
		Adjust_Candidates(G, T, k + 1, v);
	}

}
void Print_MST(MST T)
{
	int i = 0;
	int totalcost = 0;
	for (i = 0; i < n - 1; i++)
	{
		printf("%d--->%d\t%d\n", T[i].from, T[i].to, T[i].length);
		totalcost += T[i].length;
	}
	printf("TOTAL_COST=%d", totalcost);
}
int main(void)
{
	Creat_Graph(G);
	int r = 3;
	PrimMST(G, T, r);
	Print_MST(T);
	system("pause");
	return 0;
}