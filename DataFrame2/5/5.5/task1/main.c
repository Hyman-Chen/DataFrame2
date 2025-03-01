#include <stdio.h>
//输入N个数（N小于等于100），输出数字2的出现次数；
//解题提示：
//整型数组读取5个整型数的方法如下：
//int a[100];
//for(int i=0;i<5;i++)
//{
//scanf("%d",&a[i]);
//}
int main() {
    int n,i,count=0,a[100]={0};

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        if (a[i] == 2) {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
