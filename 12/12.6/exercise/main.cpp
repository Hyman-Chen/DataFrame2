#include <stdio.h>
#include <stdlib.h>
#define ElemeType int
typedef struct LNode{
    ElemeType data;
    struct LNode* next;
}LNode,*LinkList;

// 头插法创建新链表
void ListHeadInsert(LinkList &L) {
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    ElemeType x;
    scanf("%d", &x);
    LinkList s;
    while (x != 9999) {
        s = (LinkList) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
}

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

// 返回中间结点
void FindMidNode(LinkList L, LinkList &L2){
    L2 = (LinkList) malloc(sizeof(LNode));
    LinkList pcur,ppre;
    pcur = L->next;
    ppre = L->next;
    while (pcur != NULL) {
        pcur = pcur->next;
        if (pcur == NULL) break;
        pcur = pcur->next;
        if (pcur == NULL) {
            break;
        }
        ppre = ppre->next;
    }
    L2->next = ppre->next;
    ppre->next = NULL;

}

// L2 原地倒置
void Reverse(LinkList L){
    LinkList r,s,t;
    r = s = t = L->next;
    if (NULL == r) {
        return;
    }
    s = t = r->next;
    if (NULL == t) {
        return;
    }
    t = s->next;

    while (t !=NULL){
        s->next = r;
        r = s;
        s = t;
        t = t->next;
    }
    s->next = r;
    L->next->next = NULL;
    L->next = s;

}

// 交叉合并两个链表
void merge(LinkList L,LinkList L2){
    LinkList p, q, pcur;
    p = pcur = L->next;
    q= L2->next;
    p = p->next;
    while (p && q) {
        pcur->next = q;
        pcur = pcur->next;
        q = q->next;
        pcur->next = p;
        pcur = pcur->next;
        p = p->next;
    }

    if (q != NULL) {
        pcur->next = q;
    }
    if (p != NULL) {
        pcur->next = p;
    }
    ListPrint(L);

}
int main() {
    LinkList L,L2;
    printf("create L...\n");
    ListHeadInsert(L);
    printf("L:\n");
    ListPrint(L);
    printf("------------\n");
    printf("find middle element... \n");
    FindMidNode(L, L2);
    printf("L:\n");
    ListPrint(L);
    printf("L2:\n");
    ListPrint(L2);
    printf("------------\n");
    printf("reverse L2...\n");
    Reverse(L2);
    printf("reverse L2:\n");
    ListPrint(L2);
    printf("------------\n");
    printf("merge L and L2...\n");
    merge(L, L2);
    ListPrint(L);

    return 0;
}
//1 2 3 4 5 6 7 9999