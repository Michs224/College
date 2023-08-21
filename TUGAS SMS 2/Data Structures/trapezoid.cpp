#include <stdio.h>

int main(){
	int l,k,b,c;
	scanf("%d",&l);
	k=l;
	l=l/2;
	b=l;
	c=0;
	while(b<=k){
		b+=2;
		c++;
	}
	
	for(int i=0;i<c;i++){
		for(int j=0;j<k;j++){
			if(j<c-i){
				printf(" ");
			}
			else{
				for(int z=0;z<l;z++){
					printf("*");
				}
				
				l+=2;
				break;
			}
		}printf("\n");
	}
	
	return 0;
}
