#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>

#define color SetConsoleTextAttribute
HANDLE c=GetStdHandle(STD_OUTPUT_HANDLE);

clock_t spawnTime=clock(); 

int score=0,enemyhealth=3,enemyspawn=4;
char player='P',enemy='E';
int x=4;int y=30,Xenemy,Yenemy;


struct scoreplayer{
	char name[100];
	int score;
	
}dataplayer[10000];

void cls(){
	COORD cursor;
	cursor.X=0;
	cursor.Y=0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cursor);
}


void hideCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}


int randomX(){
	return rand()%7+1;
}

int randomY(){
	int y;
	y=rand()%2+1;
	if(y==2){
		return 63;
	}
	
}


void moveMents(char map[][67]){
	static int cooldown=0;
	
	if(cooldown==0){
	for(int i=0;i<9;i++){
		for(int j=0;j<65;j++){
			if(map[i][j]=='E'){
				if(j>y){
					if(map[i][j-1]=='O'){
						map[i][j-1]='.';
						score+=10;
					}
					else if(map[i][j-1]=='G')break;
					else{
					map[i][j-1]='E';
					map[i][j]='.';
					}
				}
				else{
					if(map[i][j+1]=='O'){
						map[i][j+1]='.';
						score+=10;
					}
					else if(map[i][j+1]=='G')break;
					else{
					map[i][j+1]='E';
					map[i][j]='.';
					j++;						
					}

				}
			}

		}
	}
	cooldown=10;		
	}
	cooldown--;
	
}


void bullets(char map[][67]){
	for(int i=0;i<9;i++){
		for(int j=0;j<65;j++){
			if(map[i][j]=='O'){
				if(j==1 || j==63)map[i][j]='.';
				else if(j<y){
					if(map[i][j-1]=='E'){
						map[i][j-1]='.';
						score+=10;
					}

					else{
					map[i][j-1]='O';
					map[i][j]='.';	
					}
				}
				else{
					if(map[i][j+1]=='E'){
						map[i][j+1]='.';
						score+=10;
					}

					else {
					map[i][j+1]='O';
					map[i][j]='.';
					j++;	
					}
				}
			}

		}
	}
			
	
}


void game(){
	
	char map[][67]={
	{"#################################################################"},
	{"#............................G  G...............................#"},
	{"#............................G  G...............................#"},
	{"#............................G  G...............................#"},
	{"#............................G  G...............................#"},
	{"#............................G  G...............................#"},
	{"#............................G  G...............................#"},
	{"#............................G  G...............................#"},
	{"#################################################################"}
	};
	system("cls");
	
	while(1){
	cls();
	map[x][y]=player;

	printf("\n\n			  Score: %d		 Defend Our Base!!\n\n			  ",score);
	
	for(int i=0;i<9;i++){
		for(int j=0;j<65;j++){
			printf("%c",map[i][j]);
		}printf("\n		          ");
	}
	
	printf("Enemy Health\t: %d HP\n",enemyhealth);
	printf("			  Spawn Time\t: %d Second\n",enemyspawn);

	if(kbhit()){
	
		char move=getch();
		switch(move){
			case 72:{
				if(map[x-1][y]!='G' && map[x-1][y]!='#'){
					map[x][y]=' ';
					x--;
				}

				break;
			}
			case 75:{
				if(map[x][y-1]!='G' && map[x][y-1]!='#'){
					map[x][y]=' ';
					y--;
				}
				break;
			}
			case 80:{
				if(map[x+1][y]!='G' && map[x+1][y]!='#'){
					map[x][y]=' ';
					x++;
				}
				break;
			}
			case 77:{
				if(map[x][y+1]!='G' && map[x][y+1]!='#'){
					map[x][y]=' ';
					y++;
				}
				break;
			}
			case 32:{
				if(y==30){
					map[x][y-2]='O';
				}
				else{
					map[x][y+2]='O';
				}
				break;
			}
	
		}

	}
	
	if(clock()>spawnTime){
			Xenemy=randomX();
			Yenemy=randomY();
			map[Xenemy][Yenemy]=enemy;
//			printf("%d\n",Xenemy);
			if(score<50)spawnTime=clock()+4000;
			else if(score <100){
			spawnTime=clock()+3000;
			enemyspawn=3;	
			}
			else if(score <150){
				enemyspawn=2;
				spawnTime=clock()+2000;
				
			}
			else{
				enemyhealth=5;
			}
			
		}

	
	moveMents(map);
	bullets(map);
	}


}


void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void pause(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    printf("Press any key then enter or just enter to continue . . . ");		
	int c=getchar();
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #endif
}

void exitt(){
	system("cls");
	char exit[30][100]= {"                                              .",
						 "                                             ...",
						 "                                            ..,..",
						 "                                          ....*...",
						 "                                         ..,..*.....",
						 "                                       ....*****,,....",
						 "                                     ..*,**.****,,****..",
						 "                 .....         ..... ...***...*..,***..  .....            ..",
						 "                   ..*,....*,.,*,*,..    ...,*,*,..      .,*,*,.,*,.,..*...",
						 "                    ...,,***...*,*,.  ...,******,.%.. .  ..***...****,...",
						 "                      ..,**.**,......,**,***,,&&(*******......,*,****...",
						 "                       ...*.**..,*******,, &&&*,,**,,,*******..*,,,...",
						 "                        .***,*..,***,,*,&&&&**,*,*,,,**& ***...*,***.",
						 "                        ...... ..,***,&&&&/,,***,&&&&&& ****.  ......",
						 "                          .     ..***&&&&(*,****,*/&&&//,**..     .",
						 "                        ..**,....,**&&&&&%/,,***,,&&&&/*,**,....,**.",
						 "                       .,,,,,,,.,,,&#**,,,,,,,,*&&&&/*,,,,,,,.,,,,,,.",
						 "                      ..,...**.*,*******,,***,&& /*,,********.,*...*..",
						 "                     ....*******......**,**%&(*,,******......***,***...",
						 "                   ....**.***..*,**.   .. ******,**..   ..****..,*..**...",
						 "                 .............**,*,.   .....,***.....   ..**,*.............",
						 "                                 .   ..******.,.,****,..  .",
						 "                                     ..*,*,..**,..****.",
						 "                                        ..******,*..",
						 "                                           ...*..",
						 "                                            ....",
						 "                                             .."};
						 char e[]="                                        Bluejack22-2\n\nWonderful things can be achieved when there is a teamwork, hardwork, and perseverance.";
						 int ee=strlen(e);
						 for(int i=0;i<30;i++){
						 	if(i<29)printf("%s\n",exit[i]);
						 	else printf("%s",exit[i]);
							usleep(10000);
						 }
						for(int i=0;i<ee;i++){
						 	printf("%c",e[i]);
							usleep(10000);
						 }puts("");
						 getch();
    
}

void HowToPlay(){
	system("cls");
	puts("\n                                                  How to Play\n");
    puts("                        Run n Gun is a shooting game. Enemy is trying to destroy our base.");
    puts("                        Our purpose is defend our base from enemy in the water\n");
    puts("                        We have guns to defend. We need to Run n Gun!! Kill all enemy and");
    puts("                        safe our base!\n");
    puts("						     Symbol\n");
    puts("						   P : Player");
    puts("						   G : Gun");
    puts("						   . : Water");
    puts("						   E : Enemy");
    puts("						   # : Wall\n");
    puts("						   Control\n");
    puts("					Arrow Key Down : Move Down");
    puts("					Arrow Key Up   : Move Up");
    puts("					Arrow Key Left : Move Left");
    puts("					Arrow Key Right: Move Right");
    puts("					Space          : Shoot Using Nearest Gun\n");
    printf("					     Press enter to continue!!");
    getchar(); 
    system("cls");
}

void ScoreBoards(){
	system("cls");
	FILE*scoreboard=fopen("scoreboard.txt","a+");
	int jlh=0;
	
	while(!feof(scoreboard)){
		fscanf(scoreboard,"%[^#]#%d\n",dataplayer[jlh].name,&dataplayer[jlh].score);
		jlh++;

	}
	
	int i;
	
	for(i=0;i<jlh-1;i++){
		for(int j=0;j<jlh-i-1;j++){
			if(dataplayer[j].score>dataplayer[j+1].score){
				int tukar=dataplayer[j].score;
				dataplayer[j].score=dataplayer[j+1].score;
				dataplayer[j+1].score=tukar;
			}
		}
	}
	
	puts("\n\n");
	puts("				   ------------------------------------------");
	puts("				   |        Name       |        Score       |");
	puts("				   ------------------------------------------");
	
	for(int j=0;j<i;j++){
	printf("				   |   %-10s      |   %-10d       |\n",dataplayer[j].name,dataplayer[j].score);
	}
	
	if(i==0){
		printf("				   |                 No data                |\n");
	}
	puts("				   ------------------------------------------");
	puts("\n\n");
	printf("				   	    Press enter to continue!");getchar();
	
//	system("cls");
}

void RunnGun(int x){
//	system("cls");
//hideCursor();
	puts("\n");
	puts("                                     ______                      _____");
    puts("                                     | ___ \\                    |  __ \\");
    puts("                                     | |_/ /   _ _ __    _ __   | |  \\/_   _ _ __");
    puts("                                     |    / | | | '_ \\  | '_ \\  | | __| | | | '_ \\");
    puts("                                     | |\\ \\ |_| | | | | | | | | | |_\\ \\ |_| | | | |");
    puts("                                     \\_| \\_\\__,_|_| |_| |_| |_|  \\____/\\__,_|_| |_|\n\n");
    
    if(x==1){
    color(c,12);
    puts("                                                          Play\n");
    color(c,7);
	puts("                                                       How to Play\n");
    puts("                                                       Scoreboards\n");
    puts("                                                          Exit\n\n\n\n\n\n\n\n\n");
    puts("\tArrow key [down | up] to move                                                            Enter to choose\n");
    
	}
	
	else if(x==2){
	
    puts("                                                          Play\n");
    color(c,12);
	puts("                                                       How to Play\n");
    color(c,7);
	puts("                                                       Scoreboards\n");
	puts("                                                          Exit\n\n\n\n\n\n\n\n\n");
    puts("\tArrow key [down | up] to move                                                            Enter to choose\n");
	}
	
	else if(x==3){
	
    puts("                                                          Play\n");
	puts("                                                       How to Play\n");
    color(c,12);
	puts("                                                       Scoreboards\n");
    color(c,7);
	puts("                                                          Exit\n\n\n\n\n\n\n\n\n");
    puts("\tArrow key [down | up] to move                                                            Enter to choose\n");
	}
	
	else if(x==4){
    puts("                                                          Play\n");
	puts("                                                       How to Play\n");
    puts("                                                       Scoreboards\n");
    color(c,12);
	puts("                                                          Exit\n\n\n\n\n\n\n\n\n");
    color(c,7);
	puts("\tArrow key [down | up] to move                                                            Enter to choose\n");
	}
//	system("cls");
//  getch();
}



int main(){
	hideCursor();
	srand(time(0));
	int select=1;

		while(1){
		
		cls();
			switch(select){
				case 1:{
					RunnGun(1);
					break;
				}
				case 2:{
					RunnGun(2);
					break;
				}
				case 3:{
					RunnGun(3);
					break;
				}
				case 4:{
					RunnGun(4);	
					break;
				}
			}
			
			printf("%d\n",select);
			char move=getch();
			if(move==72){
				if(select>1 && select<=4)
				select--;
			}
			else if(move==80){
				if(select>=1 && select<4)
				select++;
				printf("%d\n",select);
			}
			else if(move=='\r'){
			switch(select){
			case 1:{
				game();
				break;
			}
			
			case 2:{
				HowToPlay();
				break;
			}
			
			case 3:{
				ScoreBoards();
				break;
						
			}
			case 4:{
				exitt();
				break;
			}
			
		}
		
		}
				
		};




		
//		exitt();
	
	return 0;
}
