//
// Created by 高建 on 2017/10/23.
//


#include "Btree.h"


	BiThrTree *pre;

//Visit
int Print(char e){
	printf("(%c)",e);
	return 1;
}
//层序建立二叉树
BiThrTree *CreateBiThrTree(char *nodes,int pos ,int num){
	BiThrTree *T;
	if(nodes[pos]==' '||pos>num)
		return NULL;
	T=(BiThrTree *)malloc(sizeof(BiThrTree));
	T->data=nodes[pos];
	T->lchild=CreateBiThrTree(nodes,2*pos,num);
	T->rchild=CreateBiThrTree(nodes,2*pos+1,num);
	return T;
}
//应用队列进行输出
void DisplayTree(BiThrTree *root){
	BiThrTree *queue[MAXSIZE];
	int front,rear;
	BiThrTree *T;
	if(root==NULL)
		return;
	queue[0]=root;
	front=0;
	rear=1;
	while(front<rear){
		T=queue[front];
		front=(front+1)% MAXSIZE;
		if(T==NULL)
			printf("( )");
		else
			printf("(%c)",T->data);
		if(T!=NULL){
			queue[rear]=T->lchild;
			rear=(rear+1)% MAXSIZE;
			queue[rear]=T->rchild;
			rear=(rear+1)% MAXSIZE;
		}
	}
}
//先序遍历建立二叉树
BiThrTree *PreOrderCTree(){
	char ch;
	scanf("%c",&ch);
	BiThrTree *T;
	if(ch==' ')
		T=NULL;
	else{
		T=(BiThrTree *)malloc(sizeof(BiThrTree));
		T->data=ch;
		T->lchild=PreOrderCTree();
		T->rchild=PreOrderCTree();
	}
	return T;
}
//先序遍历二叉树
void PreOrder(BiThrTree *T){
	if(T!=NULL){
		printf("(%c)",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
	else 
		printf("( )");
}
//中序遍历二叉树
void InOrder(BiThrTree *T){
	if(T!=NULL){
		InOrder(T->lchild);
		printf("(%c)",T->data);
		InOrder(T->rchild);
	}
	else 
		printf("( )");
}
//后序遍历二叉树
void PostOrder(BiThrTree *T){
	if(T!=NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("(%c)",T->data);
	}
	else 
		printf("( )");
}
//统计节点个数
int BiThrTreeCount(BiThrTree *T){
	if(T==NULL)
		return 0;
	else
		return BiThrTreeCount(T->lchild)+BiThrTreeCount(T->rchild)+1;
}


//InOrder Threading
int InOrderThreading(BiThrTree *&Thrt,BiThrTree *T){
	BiThrTree *p;
	Thrt=(BiThrTree *)malloc (sizeof(BiThrTree));
	Thrt->LTag=Link;
	Thrt->RTag=Thread;
	Thrt->rchild=Thrt;
	if(!T)
		Thrt->lchild=Thrt;
	else{
		Thrt->lchild=T;
		pre=Thrt;
		InThreading(T);
		pre->rchild=Thrt;
		pre->RTag=Thread;
		Thrt->rchild=pre;
	}
	return 1;
}

void InThreading(BiThrTree *p){
	if(p){		
		InThreading(p->lchild);
		if(!p->lchild){				//check this point and add its before
			p->LTag=Thread;
			p->lchild=pre;
		}
		if(!pre->rchild){			//check before point and add its point to the before
			pre->RTag=Thread;
			pre->rchild=p;
		}
		pre=p;
		InThreading(p->rchild);
	}
}

int InOrderTraveras_Thr(BiThrTree *T,int (* Visit)(char e)){
	BiThrTree *lp;
	lp=T->lchild;
	printf("%d\n",lp->LTag);
	while(lp!=T){
		while(lp->LTag==Link){
			lp=lp->lchild;
			//Visit(lp->data);
		}
		Visit(lp->data);
			//return 0;
		while(lp->RTag==Thread&&lp->rchild!=T){
			lp=lp->rchild;
			Visit(lp->data);
		}
		lp=lp->rchild;
	}
	return 1;
}










