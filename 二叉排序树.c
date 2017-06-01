#include<stdio.h>
#include<stdlib.h>
typedef int KeyType;
typedef struct Node
{
	KeyType key;
	struct Node *lchild;
	struct Node *rchild;
}BSTNode,*BSTree;

int Insert_BST(BSTree *s, KeyType k)
{
	BSTree p;
	if (*s == NULL)
	{
		p = (BSTree)malloc(sizeof(BSTNode));
		p->key = k;
		p->lchild = NULL;
		p->rchild = NULL;
		*s = p;
	}
	
	else if (k < (*s)->key)
		return Insert_BST(&((*s)->lchild), k);
	else
		return Insert_BST(&((*s)->rchild), k);
}
BSTree Creat_BST(KeyType a[], int n,BSTree *p)
{
	*p = NULL;
	int i = 0;
	while (i < n)
	{
		Insert_BST(p, a[i]);
		i++;
	}
	
	return p;
}

int Pass_BST(BSTree s)

{
	
	if (s != NULL)
	{
		Pass_BST(s->lchild);
		printf("%3d", s->key);
		Pass_BST(s->rchild);
	}
	return 0;
}
BSTree Search_BST(BSTree p, KeyType k)
{
	if (p->key == k)
	{
		printf("查找成功！%d在序列中\n",p->key);
		return p;
	}
	else if (p->key > k)
		Search_BST(p->lchild, k);
	else if (p->key < k)
		Search_BST(p->rchild, k);

}
int Delete_BST(BSTree *Tptr, KeyType k)
{
	BSTNode *f = NULL, *p = *Tptr,*q,*child;
	while (p)
	{
		if (p->key == k)
			break;
		f = p;
		if (p->key > k)
			p = p->lchild;
		if (p->key < k)
			p = p->rchild;
	}
	if (!p)
		return 0;
	q = p;
	if (q->lchild&&q->lchild)
	{
		f = q;
		p = q->rchild;
		while (p->lchild)
		{
			f = p;
			p = p->rchild;
		}
	}
	child = (p->lchild) ? p->lchild : p->rchild;
	if (!f)
		*Tptr = child;
	else
	{
		if (p == f->lchild)
			f->lchild = child;
		else
			f->rchild = child;
		if (p != q)
			q->key = p->key;
	}
	free(p);
	return 0;

}


int main(void)
{
	KeyType arry[9] = { 30,12,57,23,18,3,96,75,83 };
	int len = 9;
	BSTree s;
	BSTree root;
	BSTree root_1;
	KeyType k;
	//BSTNode *p=NULL;
	Creat_BST(arry, len,&s);
	
	printf("构造出的二叉排序树：\n");
	Pass_BST(s);
	root = s;
	root_1 = s;
	printf("\n输入要查找的数：\n");
	scanf_s("%d", &k);
	Search_BST(root, k);
	printf("输入要删除的数字：");
	scanf_s("%d",&k);
	Delete_BST(&root_1, k);
	Pass_BST(s);
	printf("\n");

	system("pause");
	return 0;

}