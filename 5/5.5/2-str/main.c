#include <stdio.h>
#include <string.h>

int main() {
    //strlen
    char a[10] = "abc adf";
    printf("%d\n", strlen(a));
    //strcmp
    char b[10] = "abc";
    char c[10] = "aacd";
    printf("%d\n", strcmp(b,c));
    //strcpy
    char d[10] = "abcd";
    char e[10] = "sf";
    strcpy(e,d);
    printf("%s\n", d);
    printf("%s\n", e);

    //strcat
    char f[10] = "abc";
    char g[10] = "def";
    printf("%s\n", strcat(f,g));
    return 0;
}
