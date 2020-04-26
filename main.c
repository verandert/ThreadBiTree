#include "./bitree.h"

int main(){
    Elemtype data[] = "ABC  DE G  F  H  ";//先序二叉树列表,以此构造二叉树;
    BiTreeNode *T, *pre;
    CreateBiTree(&T, data);
    PostOrderThread(T);
    // PreOrderThread(T);
    // printf("先序遍历线索二叉树:");
    // PreOrderTraverse(T);
    // printf("\n");
    return 0;
}