//
// Created by 高建 on 2017/10/10.
//
#include "kmp.h"

int Index(SString S,SString T,int pos){
	int i,j;
	i=pos;
	j=1;
	while(i<=S[0]&&j<=T[0]){
		if(S[i]==T[j]){
			++i;
			++j;
		}
		else{
			i=i-j+2;
			j=1;
		}
	}
    //printf("%d,%d\n",i,j);
	if(j>T[0])
		return i-T[0];
	else 
		return 0;
	
}

void InitString(SString &S){
	char s;
	int i;
	i=2;
	printf("输入字符串\n");
	scanf("%c",&s);
	S[1]=s;
	while(s!='\n'){
		scanf("%c",&s);
		S[i]=s;
		i++;
	}
	S[0]=i-2;
}

void InputString(SString S){
	int i;
    printf("字符串长度为%d\n",S[0]);
	for(i=1;i<=S[0];i++)
		printf("%c",S[i]);
    putchar('\n');
}

void Kmp_getnext(SString T,int next[]){
	int i,j;
	i=1;
	j=0;
	next[1]=0;
	while(i<T[0]){
		if(j==0||T[i]==T[j]){
			++i;
			++j;
			next[i]=j;
		}
		else
			j=next[j];
	}
}

void Kmp_getnextval(SString T,int nextval[]){
	int i,j;
	i=1;
	j=0;
	nextval[1]=0;
	while(i<T[0]){
		if(j==0||T[i]==T[j]){
			++i;
			++j;
			if(T[i]!=T[j])
				nextval[i]=j;
			else
				nextval[i]=nextval[j];
		}
		else
			j=nextval[j];
	}
}

int Index_KMP(SString S,SString T,int next[]){
	int i,j;
	i=1;
	j=1;
	while(i<=S[0]&&j<=T[0]){
		if(j==0||S[i]==T[j]){
			++i;
			++j;
		}
		else j=next[j];
	}
	if(j>T[0])
		return i-T[0];
	else
		return 0;
}

