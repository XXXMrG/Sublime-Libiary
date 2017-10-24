//
// Created by 高建 on 2017/10/23.
//



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define Link 0
#define Thread 1
#define MAXSIZE 100

typedef struct BiThrTree{
	char data;
	struct BiThrTree *lchild,*rchild;
	int LTag,RTag;	
};

BiThrTree *CreateBiThrTree(char *nodes,int pos ,int num);
void DisplayTree(BiThrTree *T);
void PreOrder(BiThrTree *T);
void InOrder(BiThrTree *T);
void PostOrder(BiThrTree *T);
int BiThrTreeCount(BiThrTree *T);

BiThrTree *PreOrderCTree();