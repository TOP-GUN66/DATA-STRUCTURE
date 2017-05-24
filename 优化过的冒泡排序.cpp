#include<stdio.h>
#include<stdlib.h>
#define LEN 8

int main(void)
{
	int arry[LEN]= { 4, 3, 1, 19, 7, 12, 13, 16 };
	int i,j,temp,LastExchange;
	int len = LEN-1;
	printf("\t优化过的冒泡排序\n");
	printf("待排序序列\n");
	for (i = 0; i < LEN; i++)
		printf("%3d", arry[i]);
	i = LEN;
	while(i>1)
	{
		
		for (j = 0; j < i-1; j++)
		{
			if (arry[j] > arry[j + 1])
			{
				temp = arry[j + 1];
				arry[j + 1] = arry[j];
				arry[j] = temp;
				LastExchange = j;
			}
			


		}
		i = LastExchange;
	}
	printf("\n排序后\n");
	for (i = 0; i <LEN; i++)
		printf("%3d", arry[i]);
	printf("\n");
	system("pause");
	return 0;

}