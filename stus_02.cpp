//����ģʽƥ���㷨


#include "kmp.h"


int main() {
	SString S,T;
	int k;
	int next[MAXSTRLEN];
	InitString(S);
	InitString(T);
	InputString(S);
	InputString(T);
	//Kmp_getnext(S,next);   //δ������next
	Kmp_getnextval(T,next);
	k=Index_KMP(S,T,next);
	//k=Index(S,T,5);    //BF�㷨
	printf("��������%d\n",k);

    return 0;
}