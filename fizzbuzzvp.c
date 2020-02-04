#include <stdio.h>

void fun(int a) {
    printf("%d\n",a);
}

void fizz(int _) {
    printf("Fizz\n");
}

void buzz(int _) {
    printf("Buzz\n");
}

void fbzz(int _) {
    printf("FizzBuzz!\n");
}


int main() {
    void (*dispatch[15])(int);
    int i = 0;
 
    /* fill dispatch array with normal print */
    printf("Generating fun\n");
    for (i=1; i<15; i++) {
        dispatch[i] = &fun;
    }

    printf("Generating fizz\n");
    /* mod 3 should be Fizz */
    for (i=3; i<15; i+=3) {
        dispatch[i] = &fizz;
    }

    printf("Generating buzz\n");
    /* mod 5 should be Buzz */
    for (i=5; i<15; i+=5) {
        dispatch[i] = &buzz;
    }

    printf("Generating fbzz\n");
    /* mod 15 should be FizzBuzz */
    dispatch[0] = &fbzz;

    printf("Looping\n");
    /* Now loop */
    for (i=1; i<=100; i++) {
        int m = i % 15;
        // printf("%d %d\n", i, m);
        (*dispatch[m])(i);
    }
}