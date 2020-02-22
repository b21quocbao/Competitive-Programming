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
double a[3][3], b[3][3], sol = 0;
int s[100], n;

int GetC() {
    char c[2];
    int f;
    scanf("%c\n", &c);
    if (c[0] == 's') f = 0;
    else if (c[1] == 'm') f = 1;
    else f = 2;
    return f;
}

void Backtrack (int id) {
    if (id == n) {
        double S = 0;
        for (int i = 1; i < n; ++ i)
            S += a[s[i - 1]][s[i]] * a[s[i]][s[i + 1]];
        for (int i = 0; i <= n; ++ i)
        {
            if (s[i] == 0) printf("ss");
            else if (s[i] == 1) printf("mm");
            else if (s[i] == 2) printf("m");
            if (i < n) printf(", "); else printf(": ");
        }    
        printf("%0.2lf\n", S);
        sol += S;
        return;
    }
    for (int i = 0; i < 3; ++ i) {
        s[id] = i;
        Backtrack(id + 1);
    }
}

int main(int argc, char const *argv[])
{

    FILE* fp1 = freopen("input.txt", "r", stdin);
    FILE* fp = freopen("output.txt", "w", stdout);

    int i, j, k, l;
    for (i = 0; i < 3; ++ i)
    for (j = 0; j < 3; ++ j)
    {
        if (j < 2)
        scanf("%lf, ", &a[i][j]);
        else
        scanf("%lf\n", &a[i][j]);
        a[i][j] /= 100;
        b[i][j] = a[i][j];
    }
    s[0] = GetC();
    scanf("%d\n", &n);
    s[n] = GetC();
    Backtrack (1);
    printf ("%0.2lf", sol);
    fclose(fp);
    fclose(fp1);
    return 0;
}
