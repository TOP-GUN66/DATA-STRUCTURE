#include<stdio.h>
#include<stdlib.h>
#define N 10


void binapass(int a[], int len)
{
	int i,m,j,k;
	int low, high;
	for (j = 2; j < len; j++)
	{
		a[0] = a[j];
		low = 1;
		high = j-1;

		
			
			while(low <= high)
			{
				m = (low + high) / 2;
				if (a[0] < a[m])
					high = m - 1;
				else
					low = m + 1;

			}
			for (k = j ; k > high + 1; --k)
				a[k ] = a[k-1];
			a[high + 1] = a[0];

		}
	

}
int main(void)
{
	int a[N] = {0,2,4,3,7,6,8,1,5,9};
	printf(" 待排序的数列为：");
	for (int i = 1; i < N; i++)
		printf("%d", a[i]);

	printf("\n");
	
	binapass(a, N);
	printf("排序后的数列为:");
	for (int i = 1; i < N ; i++)
		printf("%d", a[i]);

	printf("\n");
	system("pause");
	return 0;
	
		
}