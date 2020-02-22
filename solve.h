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
#define M_PI 3.14159265358979323846 

double l[50];

void Cn (int n)
{
    if (!n) {
        printf ("Phuong trinh vo nghiem");
        return;
    }
    if (n == 10) {
        printf ("Phuong trinh vo so nghiem");
        return;
    }
    printf("Phuong trinh co %d nghiem: ", n);
    for (int i = 0; i < n; ++ i)
    printf ("%0.4lf ", l[i]);
}

void solvePt1(double a, double b) {
    if (!a && !b) Cn (10);
    if (!a && b) Cn (0);
    if (a) 
    {
        l[0] = - b /a;
        Cn (1);
    }
}

void solvePt2 (double a, double b, double c) {
    if (!a) 
    {
        solvePt1(b, c);
        return;
    }
    double d = b * b - 4 * a * c;
    if (d < 0) Cn (0);
    if (!d) 
    {
        l[0] = - b / 2 / a;
        Cn (1);
    }
    if (d > 0) 
    {
        l[0] = (- b - sqrt(d)) / 2 / a;
        l[1] = (- b + sqrt(d)) / 2 / a;
        Cn (2);
    }
}

void solvePt3 (double a, double b, double c, double d) {
    if (!a) {
        solvePt2(b, c, d);
        return;
    }
    double delta = b * b - 3 * a * c;
    double k = (9 * a * b * c - 2 * b * b * b - 27 * a * a * d) / (2 * sqrt(pow(abs(delta), 3)));
    if (delta > 0)
    {
        if (abs (k) <= 1)
        {
            l[0] = (2 * sqrt (delta) * cos (acos(k) / 3) - b) / (3 * a);
            l[1] = (2 * sqrt (delta) * cos (acos(k) / 3 - (2 * M_PI)) - b) / (3 * a);
            l[2] = (2 * sqrt (delta) * cos (acos(k) / 3 + (2 * M_PI)) - b) / (3 * a);
            Cn (3);
        } else {
            l[0] = (sqrt (delta) * abs (k)) / (3 * a * k) * (cbrt (abs (k) + sqrt (k * k - 1)) + cbrt (abs (k) - sqrt (k * k - 1))) - b / 3 / a;
            Cn (1);
        }
    } else if (!delta) {
        l[0] = (- b + cbrt (b * b * b - 27 * a * a * d)) / 3 / a;
        Cn (1);
    } else {
        l[0] = (  sqrt(abs(delta)) / 3 / a * (cbrt (k + sqrt(k * k + 1)) + cbrt (k - sqrt(k * k + 1)))) - b / 3/ a;
        Cn (1);
    }
}
