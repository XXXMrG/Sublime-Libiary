#include "kmp.h"


int main() {
	SString S,T;
	int k;
	InitString(S);
	InitString(T);
	InputString(S);
	InputString(T);

	k=Index(S,T,5);
	printf("匹配点第一次出现在位置%d",k);
    return 0;
}