#include "function.h"

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
// 层序遍历
void LevelOrder(BiTree p){
    LinkQueue Q;
    InitQueue(Q);
    BiTree T;
    EnQueue(Q, p);
    while (!IsEmpty(Q)) {
        DeQueue(Q,T);
        printf("%c", T->c);
        if (T->lchild) {
            EnQueue(Q, T->lchild);
        }
        if (T->rchild) {
            EnQueue(Q, T->rchild);
        }
    }
}

// 建树
void CreateTree(BiTree &p){
    BiTree tree;// 创建父结点
    tree = NULL;
    BiTree newTree;
    ptagT phead, ptail, pnew, pcur;
    BiElemeType c;
    while (scanf("%c", &c)) {
        if ('\n' == c) break;
        newTree = (BiTree) calloc(1, sizeof(BiTNode));
        newTree->c = c;
        pnew = (ptagT) calloc(1, sizeof(tagT));
        pnew->p = newTree;
        if (NULL == tree) {
            tree = newTree;
            ptail = phead = pcur = pnew;
            continue;
        }
        ptail->pnext = pnew;
        ptail = ptail->pnext;
        if (NULL == pcur->p->lchild) {
            pcur->p->lchild = newTree;
        } else if (NULL == pcur->p->rchild) {
            pcur->p->rchild = newTree;
            pcur = pcur->pnext;
        }
    }
    p = tree;
}
int main() {
//    BiTree tree;
//    CreateTree(tree);
//    PreOrder(tree);
//    LevelOrder(tree);
    int x;
    scanf("%c", &x);

    printf("%d",x*2);
    return 0;
}
// abcdefghij