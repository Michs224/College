#include <stdio.h>

void a(int *b){
	
	*b=8;
}


int main(){
	int b=9;
	printf("%d ",b);
	a(&b);
	printf("%d ",b);
	return 0;
}
