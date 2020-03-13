#include <stdio.h>
#include <stdlib.h>

void fun(int a)
{
    printf("Value of a: %d\n", a);
}

double add(double a, double b) {
    return a + b;
}

int main(int argc, char *argv[])
{
    int x = 5;
    fun(x);

    int y = 10;
    void (*fun_ptr)(int) = &fun;
    (*fun_ptr)(y);

    double d1, d2;


    return 0;
}