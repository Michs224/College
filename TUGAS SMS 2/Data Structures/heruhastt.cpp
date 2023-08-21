#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

struct hotel{
	char ID[8];
	char name[31];
	char phone[16];
	char room[10];
	int umur;
	int duration;
	struct hotel *next;
};

struct hotel bookinghotel(struct hotel data);

int hashtable(char id[]) {
    int total = 0;
    for (int x = 0; x <= 6 && id[x] != '\0'; x++) {
        if (isdigit(id[x])) {
            total += id[x] - 48;
        }
    }
    return total-1;
}




bool checkroom(char room[]){
	char type[4][10]={"Regular","Deluxe","Suite"};
	int i=0;
	while(type[i][0] != NULL){
		if(strcmp(room,type[i])==0){
			return true;
		}
		i++;
	}
	return false;
}

bool checkdigit(char number[]){
	int i=0,b=0;
	
	while(number[i+4]!=NULL){
		if(isdigit(number[i+4])){
			b++;
		}
		i++;
	}
	if(b==11) return true;
	else return false;
}

void insert(struct hotel **head,char name[],char phone[],int age,char room[],int night,char id[]){
	struct hotel *temp = (struct hotel*) malloc(sizeof(struct hotel));
	
	strcpy(temp->name,name); strcpy(temp->phone,phone); 
	temp->umur = age; strcpy(temp->room,room); temp->duration = night;
	strcpy(temp->ID,id);
	
	temp->next = *head;
	*head = temp;
	
}

void firstmenu(){
	printf("        +--------------------+\n");
	printf("        | Hotel GrAnsylvania |\n");
	printf("        +--------------------+\n\n");
	printf("        1. Booking Hotel\n");
	printf("        2. View Bookings\n");
	printf("        3. Delete Booking\n");
	printf("        4. Exit\n\n");
	printf("        [PRESS 1...4 FOR THE INPUT] ");
}

int main(){
	struct hotel *head[100]={NULL},data;
	char menu;
	int table=0;
	
	while(1){
		firstmenu();
		printf("\x1B[?25l");
		menu=getch();
		
		switch(menu){
			case 49:
				printf("\x1B[?25h");
				system("cls");
				data = bookinghotel(data);
				table = hashtable(data.ID);
				insert(&head[table], data.name, data.phone, data.umur, data.room, data.duration, data.ID);
				system("cls");
				break;
			case 50:
				printf("\x1B[?25h");
				system("cls");
		
				system("cls");
				break;
			case 51:
				printf("\x1B[?25h");
				system("cls");
				
				system("cls");
				break;
			case 52:
				return 0;
				break;
			default:
				system("cls");
				printf("\n       [INVALID INPUT,PLEASE INPUT CORRECT MENU]\n\n");
				break;
		}
	}
}

struct hotel bookinghotel(struct hotel data){
	
	
	printf("        Input Full Name [3..30] : ");
	do{
		fflush(stdin);
		gets(data.name); 
		if(strlen(data.name)<3 || strlen(data.name)>30){
			system("cls");
			printf("        Input Full Name [3..30] : ");
			printf("\n\n\n\n\n        [FULL NAME LENGTH MUST BETWEEN 3 AND 30]\033[1;35H");
		}
	}while(strlen(data.name)<3 || strlen(data.name)>30);
	
	printf("        Input Phone Number : ");
	do{
		fflush(stdin);
		gets(data.phone);
		if(data.phone[0]!='+' && data.phone[1]!='6' && data.phone[2]!='2' && 
		data.phone[3]!=' ' || strlen(data.phone)!=15 || !checkdigit(data.phone)){
			system("cls");
			printf("        Input Full Name [3..30] : %s\n",data.name);
			printf("        Input Phone Number : ");
			printf("\n\n\n\n        [PHONE NUMBER MUST BEGIN WITH '+62', CONTAINS WITH AT LEAST 1 SPACE\n        AND THE LENGTH MUST BE 11 (EXCLUDE +62 AND SPACE)]\033[2;30H");
		}
	}while(data.phone[0]!='+' && data.phone[1]!='6' && data.phone[2]!='2' && 
	data.phone[3]!=' ' || strlen(data.phone)!=15 || !checkdigit(data.phone));
	
	printf("        Input Age [Minimum 18] : ");
	do{
		fflush(stdin);
		scanf("%d",&data.umur);
		if(data.umur<18){
			system("cls");
			printf("        Input Full Name [3..30] : %s\n",data.name);
			printf("        Input Phone Number : %s\n",data.phone);
			printf("        Input Age [Minimum 18] : ");
			printf("\n\n\n\n        [AGE MUST BE MINIMUM 18]\033[3;34H");
		}
	}while(data.umur<18);
	
	printf("        Input Room Type [Regular | Deluxe | Suite] (Case Sensitive) : ");
	do{
		fflush(stdin);
		gets(data.room);
		if(!checkroom(data.room)){
			system("cls");
			printf("        Input Full Name [3..30] : %s\n",data.name);
			printf("        Input Phone Number : %s\n",data.phone);
			printf("        Input Age [Minimum 18] : %d\n",data.umur);
			printf("        Input Room Type [Regular | Deluxe | Suite] (Case Sensitive) : ");
			printf("\n\n\n        [ROOM TYPE MUST BE EITHER 'REGULAR' OR 'DELUXE' OR 'SUITE' (CASE SENSITIVE)]\033[4;72H");
		}
		
	}while(!checkroom(data.room));
	
	printf("        Input How Many Night You Will Stay [1...30] : ");
	do{
		fflush(stdin);
		scanf("%d",&data.duration);
		if(data.duration<1 || data.duration>30){
			system("cls");
			printf("        Input Full Name [3..30] : %s\n",data.name);
			printf("        Input Phone Number : %s\n",data.phone);
			printf("        Input Age [Minimum 18] : %d\n",data.umur);
			printf("        Input Room Type [Regular | Deluxe | Suite] (Case Sensitive) : %s\n",data.room);
			printf("        Input How Many Night You Will Stay [1...30] : ");
			printf("\n\n\n        [YOU CAN`T STAY LESS THAN 1 NIGHT OR MORE THAN 30 NIGHTS]\033[5;56H");
		}
	}while(data.duration<1 || data.duration>30);
	
	
	if(data.room[0]=='R'){
		strcpy(data.ID,"RE");
	}else if(data.room[0]=='D'){
		strcpy(data.ID,"DE");
	}else if(data.room[0]=='S'){
		strcpy(data.ID,"SU");
	}
	
	int number = 0;
    char char_number[2];
    srand(time(0));
	for(int x=0;x<3;x++){
		number = rand() % 10;
		itoa(number, char_number, 10);
		strcat(data.ID,char_number);
	}
	
	system("cls");
	
	printf("        +===============================================+\n");
	printf("        | Booking ID    : %-30s|\n",data.ID);
	printf("        +===============================================+\n");
	printf("        | Full Name     : %-30s|\n",data.name);
	printf("        | Phone Number  : %-30s|\n",data.phone);
	printf("        | Room Type     : %-30s|\n",data.room);
	printf("        | Night Stay    : %2d(s)                         |\n",data.duration);
	printf("        +===============================================+\n\n");
	
	system("pause");
	
	return data;
}
