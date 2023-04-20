#include <stdio.h>

int NUM = 0;

int f(int n) {
    NUM++;
    printf("(%d %d)입니다\n", NUM, n);
    if(n==0||n==1)
        return n;
    return f(n-1) + f(n-2);

}

int main(void) {
    f(7);
    printf("%d입니다\n", NUM);
    return 0;
}
