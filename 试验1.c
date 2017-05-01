#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>



typedef struct stuInfo
{
	char stuName[10];
	int Age;
}Elemtype;
typedef struct node
{
 Elemtype data;
 struct node *next;
}ListNode,*ListPtr;



//初始化链表并插入数据
void LinkedList_Init(ListPtr *L,int size)
{  
	ListNode *p;
	int i;
	*L=(ListNode *)malloc(sizeof(ListNode));
	(*L)->next=NULL;
	for(i=0;i<size;i++)
	{
		p=(ListNode *)malloc(sizeof(ListNode));
		printf("Input Students's name:\n");
		scanf("%s",&(p->data.stuName));
		printf("Enter student's age\n");
		scanf("%d",&(p->data.Age));
		p->next=(*L)->next;
		
     	
		(*L)->next=p;
	}
	
     

}

//打印列表数据
void LinkedList_Show(ListPtr L)
{
	ListNode *p;
	p=L->next;
	while(p!=NULL)
	{  printf("%s\t%d\n",p->data.stuName,p->data.Age);
		
		p=p->next;
	   }
}

//删除输入的位置上的节点
void LinkedList_Del(ListPtr L,int x)
{   
	int i=1;
	ListNode *pre;
	ListNode *p;
	pre=L;
	p=L->next;
	
	for(i=1;i<x;i++)
	{
		pre=pre->next;
		p=p->next;
	}
	
	
	pre->next=p->next;
	free(p);
}

//合并两个列表
void compare(ListPtr L1,ListPtr L2)
{
   ListNode *a,*b,*tmp;
	
	
	a=L1;
	b=L2->next;
while(a->next&&b)
{
	if((a->next->data.Age)>(b->data.Age))
	{
		tmp=b->next;
		b->next=a->next;
		a->next=b;
		b=tmp; 
	} 
	else
	 a=a->next;
}
if(b)
a->next=b;

}

ListPtr ListReverse(ListPtr L)
{
   ListPtr current,pnext,prev;
    if(L == NULL || L->next == NULL)
        return L;
    current = L->next;  
    pnext = current->next;
    current->next = NULL;
    while(pnext)
    {
        prev = pnext->next;
        pnext->next = current;
        current = pnext;
        pnext = prev;
        
    }
    
    L->next = current;  
    return L;
}


int main(void)
{
	ListPtr L1=NULL;
	ListPtr L2=NULL;
	ListPtr L3=NULL;

	int size;
	int n1;
	int n2;


	
	printf("Input the length:");
	scanf("%d",&size);

	LinkedList_Init(&L1,size);
	printf("List 1: \n");
	LinkedList_Show(L1);
	printf("\n");

	
	LinkedList_Init(&L2,size);
	printf("List 2: \n");
	LinkedList_Show(L2);
	printf("\n");

    printf("Input the element you want to delete in list 1:");
	scanf("%d",&n1);
	
	
	LinkedList_Del(L1,n1);
	printf("List 1:\n");
	LinkedList_Show(L1);
	printf("\n");

	
	compare(L1,L2);
	printf("new list:\n");
	LinkedList_Show(L1);
	printf("\n");
	
	ListReverse( L1);
	printf("In reverse order:\n");
	LinkedList_Show(L1);

    system("pause");
	return 0;
}

