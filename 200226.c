/*
Code by b21
Time: 09:54 Wed 26/02/2020
*/

#include <stdio.h>

int gcd (int, int);


int main()
{
    int a, b;
    printf("Nhap so nguyen dau tien:\n");
    scanf("%d", &a);
    printf("Nhap so nguyen thu 2:\n");
    scanf("%d", &b);
    printf("UCLN cua 2 so la:\n%d", gcd (a, b));
    return 0;
}

int gcd (int a, int b) {
    return (!b ? a : gcd (b, a % b));
}