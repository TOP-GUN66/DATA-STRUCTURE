#include<stdlib.h>
#include<malloc.h>
#define  ElemType int
#define MAX 10
typedef struct
{
	ElemType data[MAX];
	int front;
	int rear;

}SeqQueue;

void EnterQueue(SeqQueue *Q, ElemType e)
{
	if ((*Q).rear == MAX - 1)
	{
		printf("overflow\n");
		exit(0);
	}
	(*Q).rear++;
	(*Q).data[(*Q).rear] = e;

}
void DeleteQueue(SeqQueue *Q)
{
	
	if ((*Q).front == (*Q).rear)
	{
		printf("Empty\n");
		exit(0);
		
	}
	
	(*Q).front++;


}

int main(void)
{
	SeqQueue Q;
	Q.data[MAX] = { -1};
	Q.front = -1;
	Q.rear = -1;
	int a, b;
	ElemType c;
	printf("Input data:");
	scanf_s("%d", &a);
	EnterQueue(&Q, a);
	printf("Input data:");
	scanf_s("%d", &b);
	EnterQueue(&Q, b);

	DeleteQueue(&Q);
	
	printf("����λ��%d\n", Q.front);
	printf("��βλ��%d\n", Q.rear);


	
	system("pause");
    return 0;
}
