#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

struct node{
	
};

struct account{
	char username[100],password[100];
	double bluetoken;
};


void displayblockchain(){
	
	printf(" /$$$$$$$  /$$                     /$$   /$$  /$$$$$$  /$$                 /$$\n");
	printf("| $$__  $$| $$                    | $$  /$$/ /$$__  $$| $$                |__/\n");
	printf("| $$  \\ $$| $$  /$$$$$$   /$$$$$$$| $$ /$$/ | $$  \\__/| $$$$$$$   /$$$$$$  /$$ /$$$$$$$\n");
	printf("| $$$$$$$ | $$ /$$__  $$ /$$_____/| $$$$$/  | $$      | $$__  $$ |____  $$| $$| $$__  $$\n");
	printf("| $$__  $$| $$| $$  \\ $$| $$      | $$  $$  | $$      | $$  \\ $$  /$$$$$$$| $$| $$  \\ $$\n");
	printf("| $$  \\ $$| $$| $$  | $$| $$      | $$\\  $$ | $$    $$| $$  | $$ /$$__  $$| $$| $$  | $$\n");
	printf("| $$$$$$$/| $$|  $$$$$$/|  $$$$$$$| $$ \\  $$|  $$$$$$/| $$  | $$|  $$$$$$$| $$| $$  | $$\n");
	printf("|_______/ |__/ \\______/  \\_______/|__/  \\__/ \\______/ |__/  |__/ \\_______/|__/|__/  |__/\n");
	
	printf("1. Log In\n2. Register\n2. Exit\n>> ");

}

void entercontinue(){
	
	printf("Press enter to continue");
	getch();
}

bool checkavailablelogin(char username[100],char password[100]){
	struct account acc;
	int check=0;
	FILE*account=fopen("Accounts.txt","r");
	while(!feof(account)){
		
		fscanf(account,"%[^#]#%[^#]#%d\n",acc.username,acc.password,acc.bluetoken);
		if(strcmp(username,acc.username)==0){
			if(strcmp(password,acc.password)==0)return true;
			else check=1;
		}
	}
	if(check==0){
		printf("Username Not Found! ");
		fflush(stdin);entercontinue();
		return false;	
	}
	else if(check==1){
		printf("Incorrect Password! ");fflush(stdin);entercontinue();
		return false;
	}
	
	
	
}

void accountcreated(){
	char acccreated[100]="Account Created!, Press Enter to Continue";
	int i=0;
	while(acccreated[i]!=NULL){
		printf("%c",acccreated[i]);
		i++;
	}getchar();
}

void Withdraw(char username[100],char password[100],double bluetoken){
	
}

void Deposit(char username[100],char password[100],double bluetoken){
	
}

void MyAccount(char username[100],char password[100],double bluetoken){
	
}

void Transactions(char username[100],char password[100],double bluetoken){
	
}

void Funds(char username[100],char password[100],double bluetoken){
	int choose;
	
	do{	
		system("cls");
		printf("FUNDS\n");
		printf("-----\n\n");
		printf("Blue Tokens: %d",bluetoken);
		
		printf("1. Deposit\n2. Withdraw\n3. Back\n>> ");
		scanf("%d",&choose);
		switch(choose){
			
			
			case 1:{
				Deposit(username,password,bluetoken);
				break;
			}
			case 2:{
			 	Withdraw(username,password,bluetoken);
				break;
			 }
		}
	}while(choose!=3);
	

}

void Mainmenu(char username[100],char password[100],double bluetoken){
	int choose;
	do{
		system("cls");
		printf(" /$$      /$$           /$$                 /$$      /$$\n");
		printf("| $$$    /$$$          |__/                | $$$    /$$$\n");
		printf("| $$$$  /$$$$  /$$$$$$  /$$ /$$$$$$$       | $$$$  /$$$$  /$$$$$$  /$$$$$$$  /$$   /$$\n");
		printf("| $$ $$/$$ $$ |____  $$| $$| $$__  $$      | $$ $$/$$ $$ /$$__  $$| $$__  $$| $$  | $$\n");
		printf("| $$  $$$| $$  /$$$$$$$| $$| $$  \\ $$      | $$  $$$| $$| $$$$$$$$| $$  \\ $$| $$  | $$\n");
		printf("| $$\\  $ | $$ /$$__  $$| $$| $$  | $$      | $$\\  $ | $$| $$_____/| $$  | $$| $$  | $$\n");
		printf("| $$ \\/  | $$|  $$$$$$$| $$| $$  | $$      | $$ \\/  | $$|  $$$$$$$| $$  | $$|  $$$$$$/\n");
		printf("|__/     |__/ \\_______/|__/|__/  |__/      |__/     |__/ \\_______/|__/  |__/ \\______/\n\n");
		
		printf("Welcome, %s\n\n",username);
		
		printf("1. Funds\n2. Transactions\n3. My Account\n4. Log Out\n>> ");
		
		scanf("%d",&choose);
		
		switch(choose){
			case 1:{
//				Funds(username, password, bluetoken);
				break;
			}
			case 2:{
				Transactions(username, password, bluetoken);
				break;
			}
			case 3:{
				MyAccount(username, password, bluetoken);
				break;
			}
			
		}
		
	}while(choose!=4);
	
	
	
}

void Login(){

	
	char username[100],password[100];
	int bluetoken,check;
	do{	
		system("cls");
		printf("LOGIN\n");
		printf("-----\n\n");
		printf("Enter Username [0 to go Back] >> ");getchar();
		gets(username);
		fflush(stdin);
		if(strcmp(username,"0")==0)return;
		
		system("cls");
		printf("LOGIN\n");
		printf("-----\n\n");
		printf("Enter Password [0 to go Back] >> ");getchar();
		gets(password);
		fflush(stdin);
		if(strcmp(password,"0")==0)return;
		
		
	struct account acc;
	check=0;
	FILE*account=fopen("Accounts.txt","r");
	while(!feof(account)){
		
		fscanf(account,"%[^#]#%[^#]#%d\n",acc.username,acc.password,acc.bluetoken);
		if(strcmp(username,acc.username)==0){
			if(strcmp(password,acc.password)==0){
				bluetoken=acc.bluetoken;
			}
			else check=1;
		}
	}
	if(check==0){
		printf("Username Not Found! ");
		fflush(stdin);entercontinue();	
	}
	else if(check==1){
		printf("Incorrect Password! ");fflush(stdin);entercontinue();
	}
		
	}while(!checkavailablelogin(username,password));
	
	
	Mainmenu(username,password,bluetoken);
	
}

bool checkspace(char username[100]){
	int i=0;
	while(username[i]!=NULL){
		if(username[i]==' '){
			return false;
		}
		i++;
	}
	return true;
	
}

bool checkavailableusername(char username[100]){
	struct account acc;
	int check=1;
	FILE*account=fopen("Accounts.txt","r");
	while(!feof(account)){
		
		fscanf(account,"%[^#]#%[^#]#%d\n",acc.username,acc.password,acc.bluetoken);
		if(strcmp(username,acc.username)==0)return false;
		
	}
	if(check==1)return true;
	
	
}


void Register(){
	char username[100],password[100];
	
	do{
		system("cls");
		printf("Enter Username [0 to Cancel] >> ");getchar();gets(username);fflush(stdin);
		
		if(strlen(username)<8 || strlen(username)>25){
			printf("Username's Length Must be Between 8 and 25 Characters Long! ");entercontinue();
		}
		else if(!checkspace(username)){
			printf("Username Musn't Contain Space, ");entercontinue();
		}
		else if(!checkavailableusername){
			printf("Username Already Taken, ");entercontinue();
		}
		
	}while(strlen(username)<8 || strlen(username)>25 || !checkspace(username) || !checkavailableusername(username));
	
	system("cls");
	
}

int main(){
	
	int choose;
	do{
		system("cls");
		displayblockchain();
		scanf("%d",&choose);
		
		switch(choose){
			
			case 1:{
				Login();
				break;
			}
			
			case 2:{
				
				break;
			}
			
		}
		
		
	}while(choose!=3);
	
	
	return 0;
}
