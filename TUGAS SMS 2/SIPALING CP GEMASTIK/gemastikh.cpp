#include <stdio.h>

int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	int c[N];
	
	for(int i=0;i<N;i++){
		scanf("%d",&c[i]);
	}
	int count=0,count1=0,check;
	for(int i=0;i<N-K+1;i++){
		count=1;
		for(int j=i+1;j<i+K;j++){
			check=1;
			int p=j;
			for(int k=j;k>i;k--){
				if(c[p]==c[k-1]){
					check=0;
					break;
				}
			}count+=check;
//			printf("%d %d\n",count,check);	
		}
		if(count1<count){
			count1=count;
		}	
	}
	printf("%d\n",count1);
	return 0;
}
