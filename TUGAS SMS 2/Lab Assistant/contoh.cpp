#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

clock_t spawnCooldown = clock() + 1000;

void cls(){	
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}


void hideCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}


int main(){

    hideCursor();

    srand(time(0));

    int ordo = 20;

    char arr[ordo][ordo];
    for(int i=0; i<ordo; i++){
        for(int j=0; j<ordo; j++){
            if(i==0 || j==0 || i==ordo-1 || j==ordo-1) arr[i][j] = '#';
            else arr[i][j] = ' ';
        }
    }

    int playerCoordX = ordo/2;
    int playerCoordY = ordo/2;

    arr[playerCoordX][playerCoordY] = 'P';

    system("cls");

    while(1){

        cls();

        for(int i=0;i<ordo; printf("\n"), i++) for(int j=0;j<ordo;j++) printf("%c ",arr[i][j]);
        
        if(kbhit()){
            char input = 0;
            input = tolower(getch());

            if(input=='w'){
                if(arr[playerCoordX-1][playerCoordY]=='#') continue;
                arr[playerCoordX][playerCoordY] = ' ';
                playerCoordX--;
                arr[playerCoordX][playerCoordY] = 'P';

            }
            else if(input=='a'){
                if(arr[playerCoordX][playerCoordY-1]=='#') continue;
                arr[playerCoordX][playerCoordY] = ' ';
                playerCoordY--;
                arr[playerCoordX][playerCoordY] = 'P';

            }
            else if(input=='s'){
                if(arr[playerCoordX+1][playerCoordY]=='#') continue;
                arr[playerCoordX][playerCoordY] = ' ';
                playerCoordX++;
                arr[playerCoordX][playerCoordY] = 'P';

            }
            else if(input=='d'){
                if(arr[playerCoordX][playerCoordY+1]=='#') continue;
                arr[playerCoordX][playerCoordY] = ' ';
                playerCoordY++;
                arr[playerCoordX][playerCoordY] = 'P';

            }
        }

        if(clock()>spawnCooldown){
            int spawnX;
            int spawnY;

            do{

                spawnX = 1 + (rand() % (ordo-2));
                spawnY = 1 + (rand() % (ordo-2));

            }while(arr[spawnX][spawnY]!=' ');

            arr[spawnX][spawnY] = 'x';
            
            spawnCooldown = clock() + 1000;
        }
    }


    

    return 0;
}
