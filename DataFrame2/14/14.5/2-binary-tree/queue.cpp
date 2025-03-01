#include "function.h"

// 初始化队列
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkList) calloc(1,sizeof(LinkNode));
}
// 入队
void EnQueue(LinkQueue &Q,ElemType x){
    LinkList pnew;
    pnew = (LinkList) calloc(1,sizeof(LinkNode));
    pnew->data = x;
    Q.rear->next = pnew;
    Q.rear = Q.rear->next;
}
// 出队
bool DeQueue(LinkQueue &Q,ElemType &T){
    if (Q.front == Q.rear) return false;
    LinkList p;
    p = Q.front->next;
    Q.front->next = p->next;
    if (p == Q.rear) {
        Q.rear = Q.front;
    }
    T = p->data;
    free(p);
    return true;
}
// 判断队列是否为空
bool IsEmpty(LinkQueue Q){
    return Q.front == Q.rear;
}




