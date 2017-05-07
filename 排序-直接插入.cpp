 
#include <stdio.h>  
#include <stdlib.h>  
#define N 10  
void InsertSort(int a[], int size)
{
	int i, j,k, temp = 0;
	for (i = 1;i < size;i++)
	{
		temp = a[i];
		for (j = 0; j < i; j++)
		{
			if (temp < a[j])
			{
				for (k = i - 1; k >= j; k--)
				{
					a[k + 1] = a[k];
				}
				a[j] = temp;
				break;
			}
				
		}
	}
}



int main()
{
	int m = 0;
	int b[N] = { 9, 8, 14, 6, 5, 10, 3, 2, 1 };
	printf("=============================\n\n");
	printf("排序前的数据是:\n9 8 7 6 5 4 3 2 1\n");
	InsertSort(b, N);
	printf("排序后的结果是：\n");
	for (m = 0; m < N; m++)
	{
		printf(" %d ", b[m]);
	}
	printf("\n\n=============================\n\n");
	system("pause");
	return 0;
}
