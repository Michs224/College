#include <stdio.h>

int main(){
	int T[]={3,9,-10,29,40,2};
//	for(int i=0;i<5;i++){
//		T[i]=i;
//	}
	int n=sizeof(T)/sizeof(T[0]);
//	printf("%d\n",n);
	for(int k=0;k<6-1;k++){
		for(int j=6-1;j>=k;j--){
			if(T[j] > T[j+1]){
				int tukar=T[j];
				T[j]=T[j+1];
				T[j+1]=tukar;
			}
		}		
	}
	
	for(int i=0;i<sizeof(T)/sizeof(T[0]);i++){
		printf("%d ",T[i]);
	}
	return 0;
}
