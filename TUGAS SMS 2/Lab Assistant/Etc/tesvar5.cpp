#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 10001 // batas maksimal panjang input

int main() {
    char input[MAX_LENGTH], numbers[MAX_LENGTH], letters[MAX_LENGTH], output[MAX_LENGTH];
    int len, num_len = 0, letter_len = 0, i, j, k;

    // Membaca input dari pengguna
    fgets(input, MAX_LENGTH, stdin);
    len = strlen(input);
    if (input[len - 1] == '\n') { // Menghapus karakter newline dari input jika ada
        input[len - 1] = '\0';
        len--;
    }

    // Memisahkan angka dan huruf dari input
    for (i = 0; i < len; i++) {
        if (isdigit(input[i])) {
            numbers[num_len++] = input[i];
        } else {
            letters[letter_len++] = input[i];
        }
    }

    // Mengurutkan angka
    for (i = 0; i < num_len - 1; i++) {
        for (j = i + 1; j < num_len; j++) {
            if (numbers[i] > numbers[j]) {
                char temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // Mengurutkan huruf
    for (i = 0; i < letter_len - 1; i++) {
        for (j = i + 1; j < letter_len; j++) {
            if (tolower(letters[i])  > tolower(letters[j]) || (tolower(letters[i]) == tolower(letters[j]) && letters[i] < letters[j])) {
                char temp = letters[i];
                letters[i] = letters[j];
                letters[j] = temp;
                printf("%c %c\n",letters[i],letters[j]);
            }
        }
    }

    // Menggabungkan angka dan huruf
    k = 0;
    for (i = 0; i < num_len; i++) {
        output[k++] = numbers[i];
    }
    for (i = 0; i < letter_len; i++) {
        output[k++] = letters[i];
    }
    output[k] = '\0';

    // Menampilkan output
    printf("%s\n", output);

    return 0;
}

