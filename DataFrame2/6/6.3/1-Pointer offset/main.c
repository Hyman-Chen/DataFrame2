#include <stdio.h>

#define N 5
//指针的偏移
int main() {
    int a[N] = {1, 2, 3, 4, 5};
    int *p = a;
    for (int i = 0; i < N; ++i,p++) {
        printf("%d\n", *p);
    }
    printf("Hello, World!\n");
    return 0;
}
