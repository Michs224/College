#include <stdio.h>
#include <stdbool.h>

bool isSquare(int num) {
    int root = 1;
    while (root * root < num) {
        root++;
    }
    return root * root == num;
}

bool isKeren(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!isSquare(arr[i] * arr[j])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int answer = -1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            int subsequence[i];
            for (int k = 0; k < i; k++) {
                subsequence[k] = arr[j + k];
            }
            if (isKeren(subsequence, i)) {
                answer = i;
                break;
            }
        }
        if (answer != -1) {
            break;
        }
    }

    printf("%d\n", answer);
    return 0;
}
