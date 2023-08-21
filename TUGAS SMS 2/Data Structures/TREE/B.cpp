#include <stdio.h>

long long penghitungTILE(long long N) {
    long long mod = 1000000007;
    long long a = 0;
    long long b = 1;

    for (long long i = 0; i < N; i++) {
        long long c = b;
        b = (a+ b) % mod;
        a = c;
    }

    long long result = (b * b) % mod;
    return result;
}

int main() {
    long long N;
    scanf("%lld", &N);

    long long hasil = penghitungTILE(N);
    printf("%lld\n", hasil);

    return 0;
}