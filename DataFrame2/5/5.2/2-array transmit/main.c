#include <stdio.h>
//数组传递到子函数中，子函数的形参接收到的是指针。
void print(int a[],int length){
    for (int i = 0; i< length; ++i) {
        printf("%-3d", a[i]);
    }

}

int main(){

    int a[5] = {1, 2, 3, 4, 5};
//
//    for (int i = 0; sizeof(a) < sizeof(int); ++i) {
//        printf("%d\n", a[i]);
//    }

    print(a,5);
    printf("\n");
    return 0;
}
