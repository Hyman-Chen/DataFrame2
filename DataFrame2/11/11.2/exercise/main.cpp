#include <stdio.h>
#include <stdlib.h>

typedef int ElemeType;
typedef struct LNode{
    ElemeType data;
    struct LNode* next;
} LNode,*LinkList;

//新建头结点，L连接头结点，并通过头插法插入若干新结点
void ListHeadInsert(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode));// 头结点
    L->next = NULL;
    ElemeType x;
    scanf("%d", &x);
    LNode *s;
    while (x != 9999) {
        s = (LinkList)malloc(sizeof(LNode));// 第一个结点
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
}

void PrintList(LinkList L){
    L = L->next;
    while (L != NULL) {
        printf("%3d", L->data);
        L = L->next;
    }
    printf("\n");
}
int main() {
    LinkList L;
    ListHeadInsert(L);
    PrintList(L);
    return 0;
}
