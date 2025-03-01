#include "function.h"

// abcdefghij
int main() {
    BiTree tree;// 创建父结点
    tree = NULL;
    BiTree newTree;
    pTagT phead, ptail, pnew, pcur;
    BiElemeType c;
    while (scanf("%c", &c)) {
        if ('\n' == c) break;
        newTree = (BiTree) calloc(1, sizeof(BiTNode));
        newTree->c = c;
        pnew = (pTagT) calloc(1, sizeof(TagT));
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

    return 0;
}
