#include<stdio.h>
#include<stdlib.h>
#define LEN 9
#define LInc 4//增长序列长度

int Sort(int *Seq ,int h)
{
	int a,j;
	
	for (a = 1+h; a < LEN; a += h)
	{
		j = 1;
		while (j < a)
		{
			Seq[0] = Seq[a];
			if (Seq[j] < Seq[0])
				j += h;
			else
				break;
		}
		while (j < a)
		{
			Seq[a] = Seq[a - 1];
			a -= 1;
		}
		Seq[j] = Seq[0];
	}
	printf("增量:%d\t",h);
	for (int k = 1; k < LEN; k++)
		printf("%5d", Seq[k]);
	printf("\n");
	return Seq;
}
void Shell_Sort(int *Seq,int *Inc)
{
	int i,k;
	for (i = 0; i < 4; i++)
	{
		k = Inc[i];
		Seq = Sort(Seq, k);
	}
}

int main(void)
{
	int arry[LEN] = { 0,4,3,1,19,7,12,13,16 };
	int h = 5,k;
	int Inc[4] = {2,3,4,1};
	printf("待排序序列\n");
	for (k = 1; k < LEN; k++)
		printf("%5d", arry[k]);
	printf("\n");
	Shell_Sort(arry, Inc);


	
	printf("希尔排序后结果\n");
	for (k = 1; k < LEN; k++)
		printf("%5d", arry[k]);
	printf("\n");
	
	system("pause");
	return 0;
}