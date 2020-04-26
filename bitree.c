#include "./bitree.h"

//先序非递归构造二叉树
void CreateBiTree(BiTreeNode **T, Elemtype data[]){
    BiTreeNode **q = NULL;
    stack S;
    InitStack(&S);
    if((*T = (BiTreeNode*)malloc(sizeof(BiTreeNode)))) {
        (*T)->ltag = link;
        (*T)->rtag = thread;
        (*T)->lchild = NULL;
        (*T)->rchild = *T;
    } else exit(-1);
    q = &((*T)->lchild);
    while (*data)
    {
        if(*data != 32){
            if((*q = (BiTreeNode*)malloc(sizeof(BiTreeNode)))){
                (*q)->data = *data;
                (*q)->lchild = (*q)->rchild = NULL;
                Push(&S, q);
                q = &((*q)->lchild);
            }
        }
        else
        {
            if(EmptyStack(&S)) break;//防止出现多余字符
            q = (BiTreeNode**)Pop(&S);
            q = &((*q)->rchild);
        }
        data++;
    }
    DestroyStack(&S);
}
//中序遍历线索二叉树并加上头节点
void InOrderThread(BiTreeNode *T){
    BiTreeNode *pre;
    if(T->lchild){
        pre = T;
        InOrderTraverseThread(T, &pre);
        pre->rchild = T;
        pre->rtag = thread;
        T->rchild = pre;
    } else T->lchild = T;
}
//中序非递归遍历二叉树并线索化
void InOrderTraverseThread(BiTreeNode *T, BiTreeNode **pre){
    BiTreeNode *p;
    stack S;
    InitStack(&S);
    p = T->lchild;
    while(p || !EmptyStack(&S)){
        if(p) {
            Push(&S, p);
            p = p->lchild;
        } else
        {
            p = (BiTreeNode*)Pop(&S);
            //printf("%c ", p->data);
            if(!p->lchild) {p->ltag = thread; p->lchild = *pre;}
            if(!(*pre)->rchild) {(*pre)->rtag = thread; (*pre)->rchild = p;}
            *pre = p;
            p = p->rchild;
        }
    }
    DestroyStack(&S);
}
//中序遍历线索二叉树
void InOrderTraverse(BiTreeNode *T){
    BiTreeNode *p;
    p = T->lchild;
    while(p != T){
        while(p->ltag == link) {p = p->lchild;}
        printf(" %c", p->data); 
        while(p->rtag == thread && p->rchild != T){
            p = p->rchild;
            printf(" %c", p->data);
        }
        p = p->rchild;
    }
}

//先序非递归遍历二叉树并线索化
void PreOrderTraverseThread(BiTreeNode *T, BiTreeNode **pre){
    BiTreeNode *p;
    stack S;
    int flag = 0;
    InitStack(&S);
    p = T->lchild;
    while(p || !EmptyStack(&S))
    {
        if(p) {
            Push(&S, p);
            if(!p->lchild) {p->ltag = thread; p->lchild = *pre; flag = 1;}
            if(!(*pre)->rchild) {(*pre)->rtag = thread; (*pre)->rchild = p;}
            *pre = p;
            if(flag == 1) {p = NULL; flag = 0;}
            else
            {
                p = p->lchild;
            }
            //printf("%c ", p->data);
        } else
        {
            p = (BiTreeNode*)Pop(&S);
            if(p->rtag == thread) p = NULL;
            else p = p->rchild;
        }
    }
    DestroyStack(&S);
}

//先序遍历线索二叉树并添加头节点
void PreOrderThread(BiTreeNode *T){
    BiTreeNode *pre;
    if(T->lchild){
        pre = T;
        PreOrderTraverseThread(T, &pre);
        pre->rchild = T;
        pre->rtag = thread;
        T->rchild = pre;
    }else T->lchild = T;
}

//先序遍历线索二叉树
void PreOrderTraverse(BiTreeNode *T){
    BiTreeNode *p;
    p = T->lchild;
    while(p != T){
        printf(" %c", p->data);
        if(p->rtag == link && p->ltag == link) p = p->lchild;
        else p = p->rchild;
    }
}

//后序非递归遍历二叉树并线索化
void PostOrderTraverseThread(BiTreeNode *T, BiTreeNode **pre){
    BiTreeNode *p, *flag = NULL;
    stack S;
    InitStack(&S);
    p = T->lchild;
    while(p || !EmptyStack(&S))
    {
        if(p) {
            Push(&S, p);
            p = p->lchild;
        } else
        {
            p = (BiTreeNode*)GetTop(&S);
            if(!p->rchild) {
                p = Pop(&S);
                printf("%c ", p->data);
                if(!p->lchild) {p->ltag = thread; p->lchild = *pre;}
                if(!(*pre)->rchild){(*pre)->rtag = thread; (*pre)->rchild = p;}
                *pre = p;
                p = NULL;
            }
            else {   
                if(p->rchild == flag){
                    p = (BiTreeNode*)Pop(&S);
                    printf("%c ", p->data);
                    if(!p->lchild) {p->ltag = thread; p->lchild = *pre;}
                    if(!(*pre)->rchild) {(*pre)->rtag = thread; (*pre)->rchild = p;}
                    *pre = p;
                    flag = p;
                    p = NULL;
                } else
                {
                    flag = p->rchild;
                    p = p->rchild; 
                }
                
            }
        }
    }
    printf("\n");
    DestroyStack(&S);
}

//后序遍历线索二叉树遇到非子叶节点时需要知道节点双亲,需要替换为三叉树;
//后序遍历线索化
void PostOrderThread(BiTreeNode *T){
    BiTreeNode *pre;
    if(T->lchild) {
        pre = T;
        PostOrderTraverseThread(T, &pre);
        if(!pre->rchild) {pre->rtag = thread; pre->rchild = T;}
        T->rchild = T->lchild;
    }
}


//非线索二叉树先中后递归遍历
/*
//先序递归遍历二叉树
void PreOrderTraverseV1(BiTreeNode *T){
    if(T){
        printf("%c ", T->data);
        PreOrderTraverseV1(T->lchild);
        PreOrderTraverseV1(T->rchild);
    }
}
//中序递归遍历二叉树
void InOrderTraverseV1(BiTreeNode *T){
    if(T){  
        InOrderTraverseV1(T->lchild);
        printf("%c ", T->data);
        InOrderTraverseV1(T->rchild);
    }
}
//后序递归遍历二叉树
void PostOrderTraverseV1(BiTreeNode *T){
    if(T){
        PreOrderTraverseV1(T->lchild);
        PreOrderTraverseV1(T->rchild);
        printf("%c ", T->data);
    }
}*/