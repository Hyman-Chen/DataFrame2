#include <stdio.h>
#define ElementType int
#define Maxsize 100
typedef struct {
    ElementType num[Maxsize];
    int len;
}SqList;

void PrintList(SqList L){
    for (int i = 0; i < L.len; i++) {
        printf("%3d", L.num[i]);
    }
    printf("\n");
}

bool DelList(SqList &L, int i){
    if (i >= 1 && i <= L.len) {
        for (int j = i; j < L.len; j++) {
            L.num[j - 1] = L.num[j];
        }
        L.len--;
        return true;
    } else {
        return false;
    }
}

void ListInsert(SqList &L,int i,ElementType element){
    if (i < 1 || i > L.len + 1) {
        return;
    }
    if (L.len == Maxsize) {
        return;
    }
    for (int j = L.len; j >= i; j--) {
        L.num[j] = L.num[j - 1];
    }
    L.num[i-1] = element;
    L.len++;
}

//初始化顺序表（顺序表中元素为整型），里边的元素是1,2,3，然后通过scanf读取一个元素（假如插入的是6），
// 插入到第2个位置，打印输出顺序表，每个元素占3个空格，格式为1  6  2  3，然后scanf读取一个整型数，
// 是删除的位置（假如输入为1），然后输出顺序表  6  2  3，假如输入的位置不合法，输出false字符串。提醒，Language一定要选为C++。
int main() {
    SqList L;
    int i,j;
    bool ret;
    L.num[0] = 1;
    L.num[1] = 2;
    L.num[2] = 3;
    L.len = 3;
    scanf("%d", &i);
    ListInsert(L, 2, i);
    PrintList(L);

    scanf("%d", &j);

    ret = DelList(L,j);
    if (ret) {
        PrintList(L);
    } else {
        printf("false");
    }
    return 0;
}
