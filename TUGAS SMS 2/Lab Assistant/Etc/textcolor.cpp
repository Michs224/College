#include <stdio.h>
//#include <windows.h>
#include <unistd.h>

#define color SetConsoleTextAttribute

int main(){
	HANDLE c=GetStdHandle(STD_OUTPUT_HANDLE);
	int x=4;
	color(c,7);
	printf("Hallo\n");
	color(c,x);
	printf("Hallo\n");
	
	return 0;
}
