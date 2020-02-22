#include "solve.h"

int main(int argc, char const *argv[])
{
    double a, b, c, d;
    printf ("Nhap a, b, c, d trong ax^3 + bx^2 + cx + d = 0\n");
    scanf ("%lf %lf %lf %lf", &a, &b, &c, &d);
    solvePt3 (a, b, c, d);
    return 0;
}
