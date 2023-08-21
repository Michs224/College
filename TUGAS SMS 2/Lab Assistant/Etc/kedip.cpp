#include <stdio.h>
#include <conio.h>
int main() {
    char menu;

    printf("Pilih menu (a/b/c): ");getch();
//    menu = getchar();

    while (getchar() != '\n'); // membaca input sampai menemukan karakter newline (\n)

    printf("Menu yang dipilih: %c\n", menu);

    return 0;
}

