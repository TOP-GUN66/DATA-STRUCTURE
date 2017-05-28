#include<stdio.h>
#include<stdlib.h>
#define LEN 9

int Find_Min(int *a,int start)
{
	int min, cur;
	min = start;
	cur = start + 1;
	while (cur < LEN)
	{
		if (a[cur] < a[min])
			min = cur;
		cur++;
	}
	return min;
}
void Insert(int *a, int pos, int min)
{
	int temp;
	temp = a[min];
	a[min] = a[pos];
	a[pos] = temp;
}
int main(void)
{
	int arry[LEN] = { 8,4,3,1,19,7,12,13,16 };
	int i,min;
	printf("待排序序列\n");
	for (i = 0; i < LEN; i++)
		printf("%3d", arry[i]);
	printf("\n");
	

   for (i = 0; i < LEN-1; i++)
	{
		min = Find_Min(arry, i);
		printf("%-5d", arry[min]);
	
		Insert(arry, i, min);
		  
		printf("第%d次交换\t",i+1);
		for (int j = 0; j < LEN; j++)
			printf("%3d", arry[j]);
		printf("\n");

	}
	for ( i = 0; i < LEN; i++)
		printf("%3d", arry[i]);

	system("pause");
	return 0;

}