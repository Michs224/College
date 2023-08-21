#include <stdio.h>

int main(){
	
	int i=1;
	long jlh=0;
	while(jlh<1000000000000000000){
		jlh+=i;
		i++;
		printf("%ld %d",jlh,i);
	}
	
	
}
