#include "solve.h"

int main(int argc, char const *argv[])
{
    double a, b;
    printf ("Nhap a, b trong ax + b = 0\n");
    scanf ("%lf %lf", &a, &b);
    solvePt1 (a, b);
    return 0;
}
