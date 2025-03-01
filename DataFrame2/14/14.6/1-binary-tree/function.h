//
// Created by 七 on 2025/2/28.
//

#ifndef INC_14_4_FUNCTION_H
#define INC_14_4_FUNCTION_H
#include <stdio.h>
#include <stdlib.h>
#define BiElemeType char

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

// 前序遍历/先序遍历/深度优先遍历
void PreOrder(BiTree p){
    if (NULL != p) {
        printf("%c", p->c);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

// 中序遍历
void InOrder(BiTree p){
    if (NULL != p) {
        InOrder(p->lchild);
        printf("%c", p->c);
        InOrder(p->rchild);
    }
}

// 后序遍历
void PostOrder(BiTree p){
    if (NULL != p) {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        printf("%c", p->c);
    }
}
#endif //INC_14_4_FUNCTION_H
