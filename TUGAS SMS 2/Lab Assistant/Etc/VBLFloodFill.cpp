#include <stdio.h>

char map[11][11]={
		"##########",
		"#        #",
		"#        #",
		"#        #",
		"#   ###  #",
		"#   # #  #",
		"#   ###  #",
		"#        #",
		"#        #",
		"##########",


};

void print(){
	for(int i=0;i<11;i++){
		for(int j=0;j<11;j++){
			printf("%c",map[i][j]);
		}
		puts("");
	}
}

void floodfill(int x,int y){
	//over
	if(x<0 || x>=11){
		return;
	}
	if(y<0 || y>=11){
		return;
	}
	//border
	if(map[x][y]=='#'){
		return;
	}
	//marked
	if(map[x][y]=='m'){
		return;
	}
	map[x][y]='m';
	floodfill(x-1,y);//up
	floodfill(x+1,y);//down
	floodfill(x,y-1);//left
	floodfill(x,y+1);//right
	
}

int main(){
	print();
	floodfill(1,1);
	print();
	return 0;
	
}
