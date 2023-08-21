#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int combination(int n, int r) {
    int numerator = factorial(n);
    int denominator = factorial(r) * factorial(n - r);
    return numerator / denominator;
}

 
int main(){	
	int N;
	scanf("%d",&N);
 	int arr[N];
// 	int arr2[N];
 	
// 	printf("%d\n",combination(4,2));

 	for(int i=0;i<N;i++){
 		scanf("%d",&arr[i]);
	}
	
	int count=-1;
	
	for(int i=2;i<=N;i++){
		if(i==2){
			int v=i;
			int check=0;
			int k=0;
			for(int i=0;i<N-1;i++){
				for(int j=i+1;j<N;j++){
					double sr=sqrt(arr[i]*arr[j]);
					if((int)sr*(int)sr==arr[i]*arr[j]){
						check++;
					}
				}
			}
//			printf("%dn=2\n",check);
			if(check==combination(N,v)){
				count=v;
				break;
			}
		}
		else{
			int p=i-1;
			int check=0;
			for(int i=0;i<N-p;i++){
				int arr2[p+1];	
				arr2[0]=arr[i];
				for(int j=i+1;j<N;j++){
					int k=1;
					int x=0;
					for(int l=j;l<N;l++){
						if(x==p)break;
						arr2[k]=arr[l];
						k++;
						x++;						
					}
					int tes=0;
					for(int i=0;i<p;i++){
						for(int j=i+1;j<p+1;j++){
							double sr=sqrt(arr2[i]*arr2[j]);
							if((int)sr*(int)sr==arr2[i]*arr2[j]){
								tes=1;
								break;
							}
						}

					}
					if(tes==1)check++;					
				}

			}
//			printf("%dn>2 %d\n",check,combination(N,p+1));
			if(check==combination(N,p+1)){
			count=p+1;	
				break;
			}
		}
	}
	
	printf("%d\n",count);
 	
	return 0;
}