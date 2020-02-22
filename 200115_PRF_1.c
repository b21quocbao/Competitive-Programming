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

int main(int argc, char const *argv[])
{
    int s = 0;
    while (1) {
        int num;
        printf ("Nhap vao 1 so: ");
        scanf ("%d", &num);
        if (num == - 1) break;
        if (num % 2 == 0) s += num;
        printf ("Tong cac so chan: %d\n", s);
    }
    return 0;
}
