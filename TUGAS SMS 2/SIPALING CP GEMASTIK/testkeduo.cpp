#include <stdio.h>
#include <math.h>

int main() {
    int t;
    unsigned long long n;

    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        scanf("%llu", &n);

        if (n == 0) {
            printf("0\n");
        } else {
            unsigned int k = (unsigned int)(sqrt(8 * n +1)-1) / 2;
            unsigned long long jlh = (unsigned long long)k * (k + 1) / 2;
			printf("%llu %u\n",jlh,k);
            if (jlh > n) {
                printf("%u>\n", k - 1);
            } else 
                printf("%u=\n", k);
            
       
        }
    }

    return 0;
}

