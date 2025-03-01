#include <stdio.h>

//某人想将手中的一张面值100元的人民币换成10元、5元、2元和1元面值的票子。要求换正好40张，且每种票子至少一张。问：有几种换法？
int main() {

    int a,b,c,d,ret=0;
    for (a = 1; a <= 10; a++) {
        for (b = 1; b <= (100 - 10 * a) / 5; b++) {
            for (c = 1; c <= (100 - 10 * a - 5 * b) / 2; c++) {
                d = 100 - 10 * a - 5 * b - 2 * c;
                if (a + b + c + d != 40 || d == 0) {
                    continue;
                } else {
                    ret += 1;
                }
            }
        }
    }
    printf("%d",ret);
    return 0;
}
