#include <stdio.h>
#include <stdlib.h>

int a[100010];

void swap (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void qbsort(int td, int n, int* a) {
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < i; ++ j)
    if ((a[i] < a[j] && !td) || (a[i] > a[j] && td)) swap(a + i, a + j);
}

int main(int argc, char const *argv[]) {
    printf("Nhap vao so phan tu cua day so: \n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i)
    {
        printf("Nhap vao phan tu thu %d cua day so: \n", i + 1);
        scanf("%d", a + i);
    }
    int td;
    while (1)
    {
        printf("Nhap 1 hoac 2 de sap xep tang dan hoac giam dan: \n");
        scanf("%d", &td);
        if (td == 1 || td == 2) break;
        printf("Nhap sai cu phap\n");
    }
    double s = 0;
    for (int i = 0; i < n; ++ i) {
        s += a[i];
    }
    s /= n;
    double sol = 0;
    for (int i = 0; i < n; ++ i)
    sol += (s - a[i]) * (s - a[i]);
    sol /= n;
    printf("Phuong sai cua day so la: %lf\n", sol);
    --td;
    qbsort(td, n, a);
    printf("Day so sau khi sap xep la: ");
    for (int i = 0; i < n - 1; ++ i)
    printf("%d, ", a[i]);
    printf("%d", a[n - 1]);
    return 0;
}
