//
// Created by 七 on 2025/2/28.
//

#ifndef INC_14_4_FUNCTION_H
#define INC_14_4_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>

typedef char BiElemeType;
// 定义二叉树结点类型和二叉树类型
typedef struct BiTNode{
    BiElemeType c;
    struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;
// tag是辅助队列
typedef struct tag{
    BiTree p;// 树的某个结点的地址
    struct tag *pnext;
}tagT,*ptagT;
// 定义链表结点

typedef BiTree ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
} LinkNode,*LinkList;
// 定义列队
typedef struct {
    LinkList front, rear;
} LinkQueue;


bool IsEmpty(LinkQueue Q);
void InitQueue(LinkQueue &Q);
void EnQueue(LinkQueue &Q,ElemType x);
bool DeQueue(LinkQueue &Q,ElemType &T);
#endif //INC_14_4_FUNCTION_H
