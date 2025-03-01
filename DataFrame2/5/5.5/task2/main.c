#include <stdio.h>
#include <string.h>

int main() {
    int length,i,ret;
    char a[100],b[100];
    gets(a);
    length = strlen(a);
    for (i = 0; i < length; ++i) {
        b[i] = a[length - 1 - i];
    }
    ret = strcmp(a, b);
    if (ret > 0) {
        printf("%d", 1);
    }
    if (ret < 0) {
        printf("%d", -1);
    }
    return 0;
}
