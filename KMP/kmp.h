//
// Created by ¸ß½¨ on 2017/10/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTRLEN 225
typedef unsigned char SString[MAXSTRLEN+1];

int Index(SString S,SString T,int pos);
void InitString(SString &S);
void InputString(SString S);
void Kmp_getnext(SString T,int next[]);
void Kmp_getnextval(SString T,int nextval[]);
int Index_KMP(SString S,SString T,int next[]);