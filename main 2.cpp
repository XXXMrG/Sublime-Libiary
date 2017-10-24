
#include "Btree.h"

int main(){
    BiThrTree *T;
    int t;
    char nodes[]="RAC#FD##BEG###";
    //T=CreateBiThrTree(nodes,1,4);
    //DisplayTree(T);
    T=PreOrderCTree();
    PreOrder(T);
    //putchar('\n');
    //InOrder(T);
    putchar('\n');
    //PostOrder(T);
    t=BiThrTreeCount(T);
    printf("%d",t);
    return 0;
}