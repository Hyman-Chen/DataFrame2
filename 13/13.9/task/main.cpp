#include <stdio.h>
#define ElemType int
#define MAXSIZE 5

// 顺序表表示栈
typedef struct{
    ElemType data[MAXSIZE];
    int top;
} SqStack;

// 初始化栈
void InitStack(SqStack &S){
    S.top = -1;
}

// 入栈
void EnStack(SqStack &S, ElemType x){
    if (S.top == MAXSIZE - 1) {
        return;
    }
    S.data[++S.top] = x;
}

// 出栈
bool OutStack(SqStack &S, ElemType &e){
    if (-1 == S.top) {
        return false;
    }
    e = S.data[S.top--];
    return true;
}

// 顺序表定义循环队列
typedef struct {
    ElemType data[MAXSIZE];
    int front,rear;
} CircleQueue;

// 初始化循环队列
void InitCircleQueue(CircleQueue &Q){
    Q.front = Q.rear = 0;
}

// 入队
bool EnCircleQueue(CircleQueue &Q, ElemType x){
    if ((Q.rear + 1) % MAXSIZE == Q.front) {
        printf("false\n");
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return true;
}

// 出队
bool DeCircleQueue(CircleQueue &Q, ElemType &e){
    if (Q.front == Q.rear) {
        return false;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;

    return true;
}

int main() {
    // 栈
    SqStack S;
    InitStack(S);
    ElemType e;
    //输入三个整数3 4 5，并入栈
    for (int i = 0; i < 3; i++) {
        scanf("%d", &e);
        EnStack(S,e);
    }
    //依次出栈，打印5 4 3
    while (-1 != S.top){
        OutStack(S, e);
        printf("%2d", e);
    }
    printf("\n");
    // 队列
    CircleQueue Q;
    InitCircleQueue(Q);
    //入队
    scanf("%d", &e);
    while(EnCircleQueue(Q,e)) scanf("%d", &e);
    //出队
    while (DeCircleQueue(Q,e))  printf("%2d", e);



    return 0;
}
