#include<stdlib.h>
#include<stdio.h>
#define MAXV 7
#define MAX 100
typedef struct
{
	int u;//�ߵ���ʼ����
	int v;//�ߵ���ֹ����
	int w;//�ߵ�Ȩ��ֵ
}Edge;
int  Creat_Graph(Edge *E, int size)
{
	int c;
	char ch;
	int i = 0;
	printf("����ߵĵ�һ��������");
	scanf_s("%d", &c);

	
	while (c != -1)
	{
		E[i].u = c;
		printf("����ߵĵڶ���������");
		scanf_s("%d", &(E[i].v));
		printf("����ߵ�Ȩ��ֵ");
		scanf_s("%d", &(E[i].w));
		printf("����ߵĵ�һ��������");
		i++;
		scanf_s("%d", &c);


	}
	return i;
}
void MinspanTree_Kruskal(Edge E[], int n,int len)
{
	int i, j, k, vset[MAXV];
	int lowcost = 0;
	for (i = 0; i < n; i++)
	{
		vset[i] = i;
	}
	k = 1;
	j = 0;
	while (k < len) {

		if ((vset[E[j].u] != vset[E[j].v]))
		{
			printf("(%d-->%d)\t%d\n", E[j].u, E[j].v, E[j].w);//E���Ѿ����߰���С�����˳���ź�
			lowcost += E[j].w;
			k++;
			for (i = 0; i < n; i++)
				if (vset[i] == vset[E[j].v])
					vset[i] = vset[E[j].u];//֤����i���ڵ��Ѿ���E[j]�������ͨ
		}
		j++;
	}
	printf("total lowcost:%d\n", lowcost);

}
int main(void)
{
	Edge E[MAX];
	int len;
	len = Creat_Graph(E, MAX);
	/*for (int i = 0; i<len; i++)
	{
		printf("%d,%d,%d", E[i].u, E[i].v, E[i].w);
		printf("\n");
	}*/
	MinspanTree_Kruskal(E, MAXV,len);
	system("pause");
	return 0;
}