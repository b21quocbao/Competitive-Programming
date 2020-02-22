#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int add (int num1, int num2) {
    return num1 + num2;
}
int main(int argc, char const *argv[]) {
    printf ("number is %d", add(15, 27));
    // system("pause");
    return 0;
}
