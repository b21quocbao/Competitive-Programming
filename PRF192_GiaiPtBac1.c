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
#include "solve.h"

int main(int argc, char const *argv[])
{
    double a, b;
    printf ("Nhap a, b trong phuong trinh ax + b = 0:\n");
    scanf ("%lf %lf", &a, &b);
    solvePt1 (a, b);
    return 0;
}
