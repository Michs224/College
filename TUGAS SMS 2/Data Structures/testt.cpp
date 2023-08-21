#include <stdio.h>
#include <conio.h>

int main()
{
    char c;

    printf("Gunakan arrow key untuk menggerakkan karakter:\n");
    
    while(1) {
        c = getch();
        switch(c) {
            case 72: // Panah atas
                printf("\rUp   ");
                break;
            case 80: // Panah bawah
                printf("\rDown ");
                break;
            case 75: // Panah kiri
                printf("\rLeft ");
                break;
            case 77: // Panah kanan
                printf("\rRight");
                break;
            default:
                printf("\r      ");
        }
    }
    
    return 0;
}

