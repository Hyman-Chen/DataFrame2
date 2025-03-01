#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct {
    ElemType *elem;
    int TabelLen;
} SSTable;

void ST_Init(SSTable &ST,int len){
    ST.TabelLen = len + 1;
    ST.elem = (ElemType *)malloc(sizeof(ElemType) * ST.TabelLen);
    srand(time(NULL));
    for (int i = 1; i < ST.TabelLen; i++) {
        ST.elem[i] = rand() % 100;
    }
}

void ST_Print(SSTable ST){
    for (int i = 1; i < ST.TabelLen; i++) {
        printf("%3d", ST.elem[i]);
    }
    printf("\n");
}

int ST_Search(SSTable ST, ElemType key) {
    ST.elem[0] = key;
    int i;
    for (i = ST.TabelLen - 1; ST.elem[i] != key; i--) ;
    return i;
}
int main() {
    SSTable ST;
    ST_Init(ST, 10);

    ST_Print(ST);
    ElemType pos;
    printf("enter the number you want to search:\n");
    scanf("%d", &pos);
    printf("%d\n", ST_Search(ST, pos));

    return 0;
}
