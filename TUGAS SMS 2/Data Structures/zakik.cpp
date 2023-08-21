#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct storage{
	char cakecode[6];
	char cakename[50];
	int stock;
	int price;
} kuee[5];

void viewlist(); void early();

int main(){
//	early();
	
	start:
	int menu;
	while(menu!=3){
			strcpy(kuee[0].cakecode,"CK001"); 	strcpy(kuee[0].cakename,"Blueberry Cake");
	strcpy(kuee[1].cakecode,"CK009"); 	strcpy(kuee[1].cakename,"Chocochip Cake");
	strcpy(kuee[2].cakecode,"CK017"); 	strcpy(kuee[2].cakename,"Mayonaise Cake");
	strcpy(kuee[3].cakecode,"CK023"); 	strcpy(kuee[3].cakename,"Strawberry Shortcake");
	
	kuee[0].stock=13; 	kuee[0].price=25000; 
	kuee[1].stock=5; 	kuee[1].price=20000; 
	kuee[2].stock=24; 	kuee[2].price=30000; 
	kuee[3].stock=7; 	kuee[3].price=17500; 
		viewlist();
		scanf("%d",&menu);
		switch(menu){
			case 1:
//				sell();
				break;
			case 2:
//				add();
				break;
			default:
				printf("wrong input\n");
			break;	
		}
	}
	
	
	return 0;
}
//void early(){
//	strcpy(kuee[0].cakecode,"CK001"); 	strcpy(kuee[0].cakename,"Blueberry Cake");
//	strcpy(kuee[1].cakecode,"CK009"); 	strcpy(kuee[1].cakename,"Chocochip Cake");
//	strcpy(kuee[2].cakecode,"CK017"); 	strcpy(kuee[2].cakename,"Mayonaise Cake");
//	strcpy(kuee[3].cakecode,"CK023"); 	strcpy(kuee[3].cakename,"Strawberry Shortcake");
//	
//	kuee[0].stock=13; 	kuee[0].price=25000; 
//	kuee[1].stock=5; 	kuee[1].price=20000; 
//	kuee[2].stock=24; 	kuee[2].price=30000; 
//	kuee[3].stock=7; 	kuee[3].price=17500; 
//}

void viewlist(){
	printf(" BLUE CAKE SHOP CASHIER\n");
	printf(" ======================\n\n");
	printf(" No.\t| Cake Code\t| Cake Name\t\t\t| Available\t| Price\n");
	printf(" ---------------------------------------------------------------------------------\n");	
		for(int i=0;i<4;i++){
			printf("0%d. | %-9s | %-20s | %9lld | Rp. %lld,-\n",i+1,kuee[i].cakecode,kuee[i].cakename,kuee[i].stock, kuee[i].price);	
		}
	

	printf(" ---------------------------------------------------------------------------------\n");
	printf("Menu :\n1. Sell\n2. Add Stock\n3. Exit\nInput choice : ");
}

