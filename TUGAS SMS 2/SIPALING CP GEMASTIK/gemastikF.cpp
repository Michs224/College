#include <stdio.h>


int main(){
	int p=0,q=0,a,b,c,d,check=0;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	int i=0;
	while(1){
//		printf("%d %d %d\n",a,p,d);

		if(a<p*d) break;
		if(p*d > 100000){
			check=1;
			break;
		}
		i++;
		a+=b;
		p+=c;
	}
	if(check==1){
		printf("-1\n");
	}
	else printf("%d\n",i);
	
	return 0;
}
