//串的模式匹配算法


#include "kmp.h"


int main() {
	SString S,T;
	int k;
	int next[MAXSTRLEN];
	InitString(S);
	InitString(T);
	InputString(S);
	InputString(T);
	//Kmp_getnext(S,next);   //未修正的next
	Kmp_getnextval(T,next);
	k=Index_KMP(S,T,next);
	//k=Index(S,T,5);    //BF算法
	printf("哈哈哈哈%d\n",k);

    return 0;
}