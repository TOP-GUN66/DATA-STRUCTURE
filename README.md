# DATA-STRUCTURE
Based on C 
#include <stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Mid "DBEAFCG"
#define Pre "ABDECFG"

typedef struct Node
{
	char data;
	struct node *lchild;
	struct node *rchild;
} Node, *PNode;
void PreMidCreateTree(PNode pn, int i, int j, int len);
void PostTravelTree(PNode pn);
int Locate(char c);

int main(void)
{
	//char Pre[50] = "ABDECFG";
	//char Mid[50] = "DBEAFCG";
	PNode Root_1 = NULL;
	PNode Root_2 = NULL;

	PreMidCreateTree(Root_1, 0, 0, strlen(Pre));
	PostTravelTree(Root_1);

	printf("遍历完成\n");
	system("pause");
	return 0;

}
int Locate(char c)
{
	int i;
	for (i = 0; i<50; i++)
	{
		if (Mid[i] == c)
		   break;
	}
	return i;

}
void PreMidCreateTree(PNode pn, int i, int j, int len)
{
	
	if (len <= 0)
	{
		pn = NULL;
		return;
	}

	pn = (Node *)malloc(sizeof(Node));
	pn->data = Pre[i];
	int m = Locate(Pre[i]);
	
	
	PreMidCreateTree(pn->lchild, i + 1, j, m - j);
	PreMidCreateTree(pn->rchild, i + (m - j) + 1, m + 1, len - 1 - (m - j));

}
void PostTravelTree(PNode pn)
{
	if (pn)
	{
		PostTravelTree(pn->lchild);
		PostTravelTree(pn->rchild);
		printf("%c", pn->data);
	}
}
