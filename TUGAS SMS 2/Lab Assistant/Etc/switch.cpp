#include <stdio.h>
	
int main(){
	char orien;
	int x,y,beach=1;
	printf("Town Name: Addersfield\nOrientation ['v' or 'h']: ");scanf(" %c",&orien);
					switch(orien){
						case 'v':{
						printf("x and y coordinates [0-9] [0-9]: ");scanf("%d %d",&x,&y);
//						vertikal(x,y,"Addersfield");
						break;
						}
						case 'h':{
						printf("x and y coordinates [0-9] [0-9]: ");scanf("%d %d",&x,&y);
//						horizontal(x,y,"Addersfield");
						break;
						}
						beach++;
						printf("%d\n",beach);
						}	
	return 0;
}

