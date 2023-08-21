#include <stdio.h>
#include <math.h>


int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	
	if(pow(a,c)<pow(b,c)) printf("<\n");
	else if(pow(a,c)>pow(b,c)) printf(">\n");
	else if (pow(a,c)==pow(b,c))printf("=\n");
	
	return 0;
}
