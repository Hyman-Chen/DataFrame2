#include <stdio.h>
#include <stdlib.h>

typedef int ElemeType;
typedef struct LNode{
    ElemeType data;
    struct LNode* next;
} LNode,*LinkList;

void PrintLinkList(LinkList L){
    L = L->next;
    while (L != NULL) {
        printf("%3d", L->data);
        L = L->next;
    }
    printf("\n");
}


void ListTailInsert(LinkList &L){
    L = (LinkList) malloc(sizeof(LNode));
    printf("%d\n", L->data);
    L->next = NULL;
    ElemeType x;
    scanf("%d", &x);
    LinkList s,r=L;
    while(x!= 9999){
        s = (LinkList) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;

}

int main() {
    LinkList L;
    ListTailInsert(L);
    PrintLinkList(L);
    return 0;
}
