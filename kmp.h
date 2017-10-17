//
// Created by 高建 on 2017/10/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTRLEN 225
typedef unsigned char SString[MAXSTRLEN+1];

int Index(SString S,SString T,int pos);
void InitString(SString &S);
void InputString(SString S);