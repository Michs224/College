#include <stdio.h>
#include <unistd.h>
int main() {
   char str[] = "Ini adalah sebuah string.";
   int i = 0;

   while (str[i] != '\0') {
      putchar(str[i]);
      i++;
      sleep(1);
   }

   return 0;
}

