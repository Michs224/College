#include <stdio.h>

//int warrior(int jlh){
//	
//	
//}

int main(){
	
	int t;
	unsigned long long n;
	
	scanf("%d",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%llu",&n);
		unsigned int k=1;
		unsigned long long jlh=0;
		if(n==0)printf("%llu\n",jlh);
		else{
		while(jlh<n){
			jlh+=k;
			k++;
		}
		printf("%llu %d\n",jlh,k);
		if(jlh>n){
			printf("%u\n",k-2);
		}
		else if(jlh==n){
			printf("%u\n",k-1);
		}			
		}	

		
	}
	
	
	return 0;
}
