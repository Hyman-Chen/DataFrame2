#include <stdio.h>
#include <stdlib.h>
#define ElemeType int
typedef struct LNode{
    ElemeType data;
    struct LNode* next;
}LNode,*LinkList;

// 打印链表所有的值
void ListPrint(LinkList L) {
    L = L->next;
    while (L) {
        printf("%3d", L->data);
        L = L->next;
    }
    printf("\n");
}

// 尾插法新建链表
void ListTailInsert(LinkList &L){
    L = (LinkList) malloc(sizeof(LNode));
    ElemeType x;
    scanf("%d", &x);
    LinkList r = L,s;
    while (x != 9999) {
        s = (LinkList) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
}

// 获取链表的第SearchPos个结点
LinkList GetEleme(LinkList L, int SearchPos){
    int j = 0;
    if (SearchPos < 0) {
        return NULL;
    }
    while (L && j < SearchPos) {
        L=L->next;
        j++;
    }
    return L;
}

// 在第InsertPos个位置插入一个Element的结点
bool InsertEleme(LinkList L, int InsertPos, ElemeType Element){
    LinkList p,s;
    s = (LinkList) malloc(sizeof(LNode));
    p = GetEleme(L, InsertPos-1);
    if (p == NULL) {
        return false;
    }
    s->next = p->next;
    s->data = Element;
    p->next = s;
    return true;
}
// 删除链表的第DeletePos个结点
bool DelEleme(LinkList &L,int DeletePos){
    LinkList p,q;
    p = GetEleme(L, DeletePos - 1);
    if (p == NULL) {
        return false;
    }
    q = p->next;
    if (q == NULL) {
        return false;
    }
    p->next = q->next;
    free(q);
    return true;
}

int main() {
    LinkList L,s;
    ListTailInsert(L);
    s = GetEleme(L, 2);
    printf("%d\n", s->data);
    InsertEleme(L, 2, 99);
    ListPrint(L);
    DelEleme(L, 4);
    ListPrint(L);
    return 0;
}
