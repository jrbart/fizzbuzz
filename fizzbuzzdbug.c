#include <stdio.h>

void fun(int a) {
    printf("%d\n",a);
}

void fizz(int a) {
    printf("Fizz\n");
}

void buzz(int a) {
    printf("Buzz\n");
}

void fbzz(int a) {
    printf("FizzBuzz!\n");
}


int main() {
    void (*dispatch)(int);
    int i;
 
    /* fill dispatc
    printf("Generating fbzz\n");
    /* mod 15 should be FizzBuzz */
    dispatch = &fbzz;

    printf("Looping\n");
    /* Now loop */
    for (i=1; i<=100; i++) {
        int m = i % 15;
        printf("%d %d", i, m);
        (*dispatch)(i);
    }
}