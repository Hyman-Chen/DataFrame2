#include <stdio.h>

//判断是否是对称数
int main() {
    int i, b = 0,backup_i;
    scanf("%d", &i);
    backup_i = i;
    while (i) {
        b = b * 10 + i % 10;
        i /= 10;
    }
    if (backup_i == b) {
        printf("yes");
    } else{
        printf("no");
    }
    return 0;
}
