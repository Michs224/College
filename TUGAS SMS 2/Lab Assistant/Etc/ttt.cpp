#include <stdio.h>

int strlength(char str[]){
	int i;
	for(i=0;str[i]!=NULL;i++){
	}
	return i;
}


int main(){
	
	char str[100]={NULL};
	
	scanf("%s",str);
	
	for(int i=0;i<strlength(str);i++){
		
		printf("%c %d\n",str[i],i);
		i++;
	}
	
	
	int n=strlength(str);
	
	
	printf("%d",n);
	
	return 0;
	
}
