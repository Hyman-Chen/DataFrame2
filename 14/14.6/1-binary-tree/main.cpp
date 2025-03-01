#include "function.h"

int main() {
    BiTree pnew;
    char c;
    BiTree tree;
    tree = NULL;
    ptagT phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;
    while(scanf("%c", &c)){
        if ('\n' == c) break;
        pnew = (BiTree) calloc(1, sizeof(BiTNode));
        pnew->c = c;
        listpnew = (ptagT) calloc(1, sizeof(tagT));
        listpnew->p = pnew;
        if (NULL == tree) {
            tree = pnew;
            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;
            continue;
        } else{
            ptail->pnext = listpnew;
            ptail = listpnew;
        }
        if (NULL == pcur->p->lchild) {
            pcur->p->lchild = pnew;
        } else if (NULL == pcur->p->rchild) {
            pcur->p->rchild = pnew;
            pcur = pcur->pnext;
        }
    }
    return 0;
}
