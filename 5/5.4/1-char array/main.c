#include <stdio.h>

void print(char c[]){
    //模拟printf
    int i = 0;
    while (c[i]) {
        printf("%c",c[i]);
        i++;
    }
    printf("\n");
}
int main() {
    char a[5] = {'h','e','l','l','o'};//无结束符输出会乱码
    char b[5] = "hello";//输出也会乱码
    char c[6] = "hello";//数组初始化，最后两位是'\0'
    char e[10];
    char f[10];
    printf("%s\n",c);//使用%s输出字符串
    print(c);
    scanf("%s", c);//scanf会在字符串末尾自动添加'\0'
    printf("%s\n",c);
    scanf("%s%s", e, f);//scanf输入两个字符
    printf("e=%s,f=%s", e, f);
    return 0;
}
