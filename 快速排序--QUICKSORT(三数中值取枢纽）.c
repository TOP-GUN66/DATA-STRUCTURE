#include<stdio.h>
#include<stdlib.h>
#define LEN 9

int GetPivot(int* Sq, int left, int right)
{
	int center = (left + right) / 2;
	int temp;
	if (Sq[left] < Sq[center])
	{
		temp = Sq[center];
		Sq[center] = Sq[left];
		Sq[left] = temp;
	}
	if (Sq[left] > Sq[right])
	{
		temp = Sq[right];
		Sq[right] = Sq[left];
		Sq[left] = temp;
	}
	if (Sq[center] > Sq[right])
	{
		temp = Sq[right];
		Sq[right] = Sq[center];
		Sq[center] = temp;
	}
	temp = Sq[right];
	Sq[right] = Sq[center];
	Sq[center] = temp;
	
	return Sq[right];
}




void Quick_Sort(int* Sq,int left,int right)
{
	if (right - left >= 3)
	{
		int pivot, i, j, temp;
		pivot = GetPivot(Sq, left, right);

		for (int k = 0; k < LEN; k++)
			printf("%3d", Sq[k]);
		printf("\n");

		i = left;
		j = right - 1;

		while (1)
		{
			while (Sq[i] < pivot)
				i++;
			while (Sq[j] > pivot)
				j--;
			if (i < j)
			{
				temp = Sq[j];
				Sq[j] = Sq[i];
				Sq[i] = temp;
			}
			else break;

		}
		
		temp = Sq[right];
		Sq[right] = Sq[i];
		Sq[i] = temp;// ‡≈¶‘™∏¥Œª
		
		
		Quick_Sort(Sq, left, i - 1);
		Quick_Sort(Sq, i + 1, right);
	}
	

}

void InsertSort(int a[], int size)
{
	int i, j, k, temp = 0;
	for (i = 1; i < size; i++)
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

int main(void)
{
	int arry[LEN] = { 8,4,3,1,19,7,12,13,16 };
	int left, right;
	left = 0;
	right = 8;
	printf("¥˝≈≈–Ú–Ú¡–");
	for (int i=0; i < LEN; i++)
		printf("%3d", arry[i]);
	printf("\n");
	Quick_Sort(arry, left, right);
	InsertSort(arry, LEN);
	printf("\n≈≈–Ú∫Û–Ú¡–\n");
	for (int i = 0; i < LEN; i++)
		printf("%3d", arry[i]);
	printf("\n");


	system("pause");
	return 0;

}
