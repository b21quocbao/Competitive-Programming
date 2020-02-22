#include "solve.h"

int main(int argc, char const *argv[])
{
    double a, b, c;
    printf ("Nhap a, b, c trong ax^2 + bx + c = 0\n");
    scanf ("%lf %lf %lf", &a, &b, &c);
    solvePt2 (a, b, c);
    return 0;
}
