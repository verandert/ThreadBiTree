#ifndef _BITREE_H_
#define _BITREE_H_
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define fasle 0
enum ThreadTag {link, thread};//线索标签link==0指向子节点, thread==1指向前驱或后继

typedef char Elemtype;
typedef struct BiTreeNode
{
    Elemtype data;
    enum ThreadTag ltag, rtag;
    struct BiTreeNode *lchild, *rchild;
}BiTreeNode;//tree节点数据类型

//布尔数据类型
typedef int boolean;

//链表节点
typedef struct StackNode
{
    void* data;
    struct StackNode *next;
}StackNode;

//链表实现栈
typedef struct
{
    StackNode *base, *top;
    int length;
}stack;

//栈相关函数的声明
void InitStack(stack *S);
void DestroyStack(stack *S);
void ClearStack(stack *S);
boolean EmptyStack(stack *S);
void Push(stack *S, void* elemtype);
void* Pop(stack *S);
void* GetTop(stack *S);

//tree相关函数声明
void CreateBiTree(BiTreeNode **T, Elemtype data[]);//字符串先序构造二叉树
void InOrderThread(BiTreeNode *T);//中序非递归遍历二叉树并线索化
void InOrderTraverseThread(BiTreeNode *T, BiTreeNode **pre);//中序非递归遍历二叉树
void InOrderTraverse(BiTreeNode *T);
void PreOrderTraverseThread(BiTreeNode *T, BiTreeNode **pre);
void PreOrderThread(BiTreeNode *T);
void PreOrderTraverse(BiTreeNode *T);//先序非递归遍历二叉树
void PostOrderTraverseThread(BiTreeNode *T, BiTreeNode **pre);//后序遍历线索化
void PostOrderThread(BiTreeNode *T);//后序线索二叉树
// void PostOrderTraverse(BiTreeNode *T);//后序非递归遍历二叉树
// void InOrderTraverseV1(BiTreeNode *T);//中序递归遍历二叉树
// void PreOrderTraverseV1(BiTreeNode *T);//先序递归遍历二叉树
// void PostOrderTraverseV1(BiTreeNode *T);//后序递归遍历二叉树

#endif