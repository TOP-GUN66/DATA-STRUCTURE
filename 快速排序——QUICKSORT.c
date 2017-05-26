#include<stdio.h>
#include<stdlib.h>
#define LEN 10
int Quick_patrition(int *Sq, int left, int right)
{
	
	
	Sq[0] = Sq[left];
	
		while (left < right)
		{
			while (left < right&&Sq[right] >=Sq[0])
				right--;
			if (left < right)
			{
				Sq[left] = Sq[right];
				left++;
			}
			while (left < right&&Sq[left] <= Sq[0])
				left++;
			if (left < right)
			{
				Sq[right] = Sq[left];
				right--;
			}
			
		}
		Sq[left] = Sq[0];
		
		return left;
}
void Quick_sort(int *Sq, int i, int j)

{
	int k;
	if (i < j)
	{
		k = Quick_patrition(Sq, i, j);
	    Quick_sort(Sq, i, k - 1);
		Quick_sort(Sq, k + 1, j);
	}

}
int main(void)
{
	int arry[LEN] = { 0,8,4,3,1,19,7,12,13,16 };
	int low = 1, high = 9,k;
	printf("待排序数列:\n");
	for (k = 1; k < LEN; k++)
		printf("%3d", arry[k]);
	printf("\n");

	Quick_sort(arry, low, high);
	printf("排序后的数列:\n");
	for ( k = 1; k < LEN; k++)
		printf("%3d", arry[k]);
	printf("\n");
	system("pause");
	return 0;

}
