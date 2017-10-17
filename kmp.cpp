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