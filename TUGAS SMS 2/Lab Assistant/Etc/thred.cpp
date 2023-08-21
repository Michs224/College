#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *thread1(void *arg);
void *thread2(void *arg);

int stop_thread2 = 0; // flag untuk menghentikan thread2

int main()
{
    pthread_t tid1, tid2;

    // membuat thread 1
    pthread_create(&tid1, NULL, thread1, NULL);

    // membuat thread 2
    pthread_create(&tid2, NULL, thread2, NULL);

    // menunggu kedua thread selesai
    pthread_join(tid1, NULL);
//    pthread_join(tid2, NULL);

    printf("Program selesai.\n");

    return 0;
}

void *thread1(void *arg)
{
    char input;
    while (1) {
        printf("Masukkan huruf 'q' untuk keluar: ");
        scanf("%c", &input);

        if (input == 'q') {
            printf("Menunggu thread 2 untuk keluar...\n");
            stop_thread2 = 1; // memberi flag untuk menghentikan thread2
            break;
        }
    }

    pthread_exit(NULL);
}

void *thread2(void *arg)
{
    while (!stop_thread2) {
        printf("Thread 2 masih berjalan...\n");
        sleep(1);
    }

    printf("Thread 2 berhenti.\n");

    pthread_exit(NULL);
}

