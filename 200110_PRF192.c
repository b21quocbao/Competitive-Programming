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
#include <stdbool.h>

void Hello() {
	printf("Hello. We have one week before Tet..."); //string
}

void choGa() {
	int i,k = 0;
	for (i=0; i<=36; ++i) 
		for (k=0; k<=36; ++k)
			if ((i + k == 36) && (2 * i + 4 * k == 100))
				printf ("So cho la: %d, so ga la: %d\n", i, k);
}

void tramTrauTramCo() {
	int d, n, g;
	for (d=0; d<=100; ++d)
		for (n=0; n<=100; ++n)
			for (g=0; g<=100; g += 3)
				if (d + n + g == 100 && 5 * d + 3*n + g / 3 == 100)
					printf("Trau dung %d, trau nam %d, trau gia %d\n", d, n, g);
}

bool primeCheck(int n) {
	if (n < 2) return 0;
	int i;
	for (i = 2; i * i <= n; ++ i)
	if (n % i == 0) return 0;
	return 1;
}

void lietKe (int n) {
	int i;
	for (i=0; i<=n; ++i)
		if (primeCheck(i) && primeCheck(n - i)) 
			printf("%d = %d + %d\n", n, i, n - i);
	for (i=1; i<=n; ++i)
		if (n % i == 0 && primeCheck(i) && primeCheck(n / i)) 
			printf("%d = %d X %d\n", n, i, n / i);
}

void isEven(int n) {
    return ((n & 1) ^ 1);
}

int main(int argc, char const *argv[]) {
	while (1) {
		int n;
		scanf("%d", &n);
		lietKe(n);
	}
	
    return 0;
}
