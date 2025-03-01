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

void CreateTree(BiTree &tree){
    BiTree pnew;
    ptagT listpnew=NULL,phead=NULL,ptail=NULL,pcur;
    tree = NULL;
    BiElemeType c;
    while (scanf("%c", &c)) {
        if ('\n' == c) break;
        pnew = (BiTree) calloc(1,sizeof(BiTNode));
        pnew->c = c;
        listpnew = (ptagT) calloc(1,sizeof(tagT));
        listpnew->p = pnew;
        if (NULL == tree) {
            tree = pnew;
            ptail = phead = pcur = listpnew;
            continue;
        }
        ptail->pnext = listpnew;
        ptail = ptail->pnext;
        if (NULL == pcur->p->lchild) {
            pcur->p->lchild = pnew;
        }else if(NULL == pcur->p->rchild){
            pcur->p->rchild = pnew;
            pcur = pcur->pnext;
        }

    }
}

// 前序
void PreOrder(BiTree T){
    if (NULL != T) {
        printf("%c", T->c);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

int main() {
    BiTree T;
    CreateTree(T);
    PreOrder(T);
    return 0;
}
// abcdefghij