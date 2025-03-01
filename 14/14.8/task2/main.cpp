#include <stdio.h>
#include <stdlib.h>

// 二叉树
typedef char BiElemType;
typedef struct BiTNode{
    BiElemType c;
    struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

// 建树辅助队列
typedef BiTree ElemType;
typedef struct tagT{
    ElemType p;
    tagT *pnext;
} tagT,*ptagT;

// 链表结点
typedef struct LinkNode{
    ElemType p;
    struct LinkNode *pnext;
} LinkNode, *LinkList;

// 队列
typedef struct {
    LinkList front, rear;
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkList) calloc(1, sizeof(LinkNode));
}

// 入队
void EnQueue(LinkQueue &Q, ElemType T) {
    LinkList pnew;
    pnew = (LinkList) calloc(1, sizeof(LinkNode));
    pnew->p = T;
    Q.rear->pnext = pnew;
    Q.rear = Q.rear->pnext;
}

bool DeQueue(LinkQueue &Q, ElemType &T){
    if (Q.front == Q.rear) return false;
    LinkList q = Q.front->pnext;
    Q.front->pnext = q->pnext;
    if (q == Q.rear) Q.rear = Q.front;
    T = q->p;
    return true;
}

bool IsEmpty(LinkQueue Q){
    return Q.front == Q.rear;
}
// 创建树
void CreateTree(BiTree &tree){
    tree = NULL;
    BiTree treeNew;
    ptagT phead = NULL,ptail = NULL,pcur = NULL,pnew = NULL;
    BiElemType c;
    while (scanf("%c", &c)) {
        if ('\n' == c) break;
        treeNew = (BiTree) calloc(1, sizeof(BiTNode));
        treeNew->c = c;
        pnew = (ptagT) calloc(1, sizeof(tagT));
        pnew->p = treeNew;
        if (!tree) {
            tree = treeNew;
            phead = ptail = pcur = pnew;
            continue;
        }
        ptail->pnext = pnew;
        ptail = ptail->pnext;
        if (NULL == pcur->p->lchild){
            pcur->p->lchild = treeNew;
        } else if (NULL == pcur->p->rchild) {
            pcur->p->rchild = treeNew;
            pcur = pcur->pnext;
        }
    }
}

void InOrder(BiTree T){
    if (NULL != T) {
        InOrder(T->lchild);
        printf("%c", T->c);
        InOrder(T->rchild);
    }
}
void PostOrder(BiTree T){
    if (NULL != T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->c);
    }
}

void LevelOrder(BiTree T){
    LinkQueue Q;
    BiTree loctree;
    InitQueue(Q);
    EnQueue(Q, T);
    while (!IsEmpty(Q)){
        DeQueue(Q, loctree);
        printf("%c", loctree->c);
        if (loctree->lchild != NULL) {
            EnQueue(Q, loctree->lchild);
        }
        if (loctree->rchild != NULL) {
            EnQueue(Q, loctree->rchild);
        }
    }
}

// abcdefghij
int main() {
    BiTree tree;
    CreateTree(tree);
    InOrder(tree);
    printf("\n");
    PostOrder(tree);
    printf("\n");
    LevelOrder(tree);

    return 0;
}
