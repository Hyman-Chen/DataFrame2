#include <stdio.h>

int main() {

    char c[20];
    gets(c);//一次读取一行

    printf("%s\n",c);
    return 0;
}
