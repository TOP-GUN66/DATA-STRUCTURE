#include<stdio.h>
#include<stdlib.h>
#define N 9
#define LEN N+1

void Build_Heap(int *a,int n)//BUILD-MAX-HEAP
{
	int i,temp;
	for (i=n/2; i>0 ; i--)
	{
		if (a[i] < a[2*i])
		{
			temp = a[2 * i];
			a[2 * i] = a[i];
			a[i] = temp;

		}
		if (a[i] < a[2 * i + 1])
		{
			temp = a[2 * i+1];
			a[2 * i+1] = a[i];
			a[i] = temp;

		}
	}
}
void Heap_Sort(int *a)
{
	int i,k,temp;
	int status1,status2;
	

	for (i = 0; i < N; i++)
	{
		printf("%3d", a[1]);
		a[1] = a[N - i];
		k = 1;
		while (k <( N - i)/2)
		{
			int Larger = a[2 * k] > a[2 * k + 1] ? 2 * k : 2 * k + 1;
			temp = a[Larger];
			a[Larger] = a[k];
			a[k] = temp;
			k = Larger;

		
		}
		if ((2 * k) <N - i)
		{
			temp = a[2 * k];
			a[2 * k] = a[k];
			a[k] = temp;
		}
		if (k == 1 && N-i==3)
		{
			temp = a[2];
			a[2] = a[1];
			a[1] = temp;
		}
		

	}
}
void Print_Arry(int *a)
{
	int k;
	for (k = 1; k < LEN; k++)
		printf("%3d", a[k]);
	printf("\n");
}
int main(void)
{
	int arry[LEN] = { 0,4,1,3,2,16,9,10,14,8 };
	int k;
	printf("待排序序列\t");
	Print_Arry(arry);
	for (k = N; k > 0; k--)
		Build_Heap(arry, k);
	printf("构造大顶堆\t");
	Print_Arry(arry);
	printf("堆排序之后\t");
	Heap_Sort(arry);
	printf("\n");

	system("pause");
	return 0;
}