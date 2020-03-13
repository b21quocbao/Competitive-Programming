/**
 *	 Code by b21
 *	 Time: 09:58 Wed 11/03/2020
**/

#include <stdio.h>
#include <stdlib.h>
int a[10010];

void swap (int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sortByReference(int* a, int n) {
    int i, j;
    for (i = 0; i < n; ++ i)
    for (j = 0; j < i; ++ j)
    if (*(a + i) < *(a + j))
    swap (a + i, a + j);
}

int main() {
    int i;
    int n;
    printf("Nhap vao so nguyen:\n");
    scanf("%d", &n);
    for (i = 0; i < n; ++ i)
    scanf("%d", a + i);
    sortByReference(a, n);
    for (i = 0; i < n; ++ i)
    printf("%d ", a[i]);
    return 0;
}