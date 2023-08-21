#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

										//PROGRAM MICH BANK
										
//Struktur untuk menyimpan informasi tentang transaksi.
struct transaction{
	char name[50];
	int day;
	int month;
	int year;
	
}trans[10000000];

//Function untuk menghitung bunga
float interestTable(int save,int y){
    if(save <1000000){
            if(y>=12&&y<36){
                return  0.01;
            }
            else if(y>=36&&y<60){
                return  0.012;
            }
            else if(y>=60&&y<120){
                return  0.015;
            }
        }
    else if (save>=1000000){
            if(y>=12&&y<36){
                return  0.012;
            }
            else if(y>=36&&y<60){
                return  0.015;
            }
            else if(y>=60&&y<120){
                return  0.017;
            }
    }
}


int main(){
	time_t now;
    struct tm *date;
    time(&now);
    date = localtime(&now);
	int choose;
	char again;
	while(again!='n'){
	printf("$$-----------------------------------------------------------------------------------------$$\n");
	printf("$$-----------------------------------------------------------------------------------------$$\n");
	printf("$$                                                                                         $$\n");        
	printf("$$  ***     ***  *****  *****   **   **    ********       ***       ***    **  **    **    $$\n");
    printf("$$  ****   ****   ***  * *****  **   **    **     **     *****      ****   **  **   **     $$\n");
    printf("$$  **  ***  **    *   * *      *******    *********    **   **     ** **  **  ** **       $$\n");
    printf("$$  **       **    *   * *      *******    *********   *********    **  ** **  ** **       $$\n");
    printf("$$  **       **   ***  * *****  **   **    **     **  **       **   **   ****  **   **     $$\n");
    printf("$$  **       **  *****  *****   **   **    ********  **         **  **    ***  **     **   $$\n");
    printf("$$                                                                                         $$\n");
    printf("$$-----------------------------------------------------------------------------------------$$\n");
	printf("$$-----------------------------------------------------------------------------------------$$\n\n");
	printf("\t\t\t\t   WELCOME TO MICH BANK!\n\n");
	labelinvalid:
	printf("SELECT THE FEATURE YOU WANT ACCORDING TO THE NUMBER:\n1. Deposits (Interest calculations per year (Annual) of 5%%)\n2. Planned Savings\n3. Planned Savings Transactions Check\n4. Exit\n\n");
	printf("Choice: ");
	scanf("%d",&choose);
	system("cls");
	float interestMonth;
	long long int i,saving,month,autodebetDay,sum=0,summ=0,check=0;
	
	char name[50],savingName[100],savingnamee[100];


	switch(choose){
		case (1) : 	printf("BINUS BANK DEPOSITS\n\n");
					printf("Name\t\t\t: "); scanf(" %[^\n]",name);
					printf("Saving\t\t\t: Rp. "); scanf("%lld",&saving);
				   	printf("Term of deposit (month)\t: "); scanf("%lld",&month);
				   	system("cls");
				   	while(saving<1000000){
				   		printf("BINUS BANK DEPOSITS\n\n");
				   		printf("MINIMUM DEPOSIT RP. 1.000.000, INPUT AGAIN!\n\n");
				   		printf("Name\t\t\t: "); scanf(" %[^\n]",name);
				   		printf("Saving\t\t\t: Rp. "); scanf("%lld",&saving);
				   		printf("Term of deposit (month)\t: "); scanf("%lld",&month);
				   		system("cls");
					   }
					   printf("TRANSACTION SUCCESSFUL!\n\n");
					   printf("DEPOSITO REPORT\n\n");
					FILE*deposit=fopen("Deposit Report.txt","a+");
					fprintf(deposit,"Date of Creation: %d-%d-%d\n%s\n",date->tm_mday, date->tm_mon+1, date->tm_year + 1900,name);
					fprintf(deposit,"+-------------------------------+-----------------------+\n");
					fprintf(deposit,"|             MONTH             |         AMOUNT        |\n");	
					fprintf(deposit,"+-------------------------------+-----------------------+\n");
					
					printf("+-------------------------------+-----------------------+\n");
					printf("|             MONTH             |         AMOUNT        |\n");	
					printf("+-------------------------------+-----------------------+\n");
				  	for (i=1;i<=month;i++){
			   	  	interestMonth= saving*(0.05/12)*0.8;
					saving+=interestMonth;
				   	if(i%10==1 && i!= 11){
				   	fprintf(deposit,"| %dst month deposit\t\t| Rp. %lld,- \t|\n",i,saving);
				   	printf("| %dst month deposit\t\t| Rp. %lld,- \t|\n",i,saving);
				   	}
				  	else if (i%10==2 && i!= 12){
				  	fprintf(deposit,"| %dnd month deposit\t\t| Rp. %lld,- \t|\n",i,saving);
				   	printf("| %dnd month deposit\t\t| Rp. %lld,- \t|\n",i,saving);
				  	}
				  	else if (i%10==3 && i!= 13){
				  	fprintf(deposit,"| %drd month deposit\t\t| Rp. %lld,- \t|\n",i,saving);
				   	printf("| %drd month deposit\t\t| Rp. %lld,- \t|\n",i,saving);
				  	}
				   	else if(i%12==0){
				   	fprintf(deposit,"| %dth month (%d year) deposit\t| Rp. %lld,- \t|\n",i,i/12,saving);
				   	printf("| %dth month (%d year) deposit\t| Rp. %lld,- \t|\n",i,i/12,saving);
				  	}
				  	else{
				  		fprintf(deposit,"| %dth month deposit\t\t| Rp. %lld,- \t|\n",i,saving);
						printf("| %dth month deposit\t\t| Rp. %lld,- \t|\n",i,saving);
					  }
			      	}
			      	fprintf(deposit,"+-------------------------------+-----------------------+\n");
			      	printf("+-------------------------------+-----------------------+\n");
					fprintf(deposit,"\n");
			      	fclose(deposit);
			      	printf("\nDO YOU WANT TO DO ANOTHER TRANSACTION? (y/n): "); scanf(" %c",&again);
			      	system("cls");
			    	break;

		case (2) :			
			printf("BINUS BANK PLANNED SAVING\n\n");
			
			printf("THE PLANNED SAVINGS ACCOUNT HAS THE FOLLOWING INTEREST RATE PROVISIONS:\n");
			printf("Monthly Routine:\n1. <1.000.000\n   Deposit Interest rate per year, can change at any time:\n");
			printf("   1 to <3 years: 1%%\t  3 to <5 years: 1,2%%\t 5 to <10 years: 1,5%%\n\n");
			printf("2. >=1.000.000\n   Deposit Interest rate per year, can change at any time:\n");
			printf("   1 to <3 years: 1,2%%\t  3 to <5 years: 1,5%%\t 5 to <10 years: 1,7%%\n\n");
			
			printf("Name of Savings Plan (Min. 7 Characters - Max. 25 Characters): "); scanf(" %[^\n]",savingName);
			system("cls");
			while(strlen(savingName)<7 || strlen(savingName)>25){
				printf("THE NAME OF THE SAVINGS PLAN MUST BE AT LEAST 7 CHARACTERS, INPUT AGAIN!\n\n");
				printf("Name of Savings Plan (Min. 7 Characters - Max. 25 Characters): "); scanf(" %[^\n]",savingName);
				system("cls");
			}
			printf("BINUS BANK PLANNED SAVING\n\n");
			printf("Nominal Savings Every Month: Rp. "); scanf("%lld",&saving);
			system("cls");
			printf("BINUS BANK PLANNED SAVING\n\n");
			printf("Saving Period (Minimum 12 months): "); scanf("%lld",&month);
			system("cls");
			while(month<12 || month >=120){
				printf("THE SAVING PERIOD MUST BE AT LEAST 12 MONTHS, INPUT AGAIN!\n\n");
				printf("Saving Period (Minimum 12 months): "); scanf("%lld",&month);
				system("cls");
			}
			printf("BINUS BANK PLANNED SAVING\n\n");
			printf("Set Autodebit Date (1-28): "); scanf("%lld",&autodebetDay);
			system("cls");
			while(autodebetDay<1 || autodebetDay>28){
				printf("ERROR, ENTER THE CORRECT DATE!\n\n");
				printf("Set Autodebit Date (1-28): "); scanf("%lld",&autodebetDay);
				system("cls");
			}
		FILE*plannedsavings=fopen("Planned Saving Report.txt","a+");
		fprintf(plannedsavings,"Date of Creation: %d-%d-%d\n%s\n",date->tm_mday, date->tm_mon+1, date->tm_year + 1900,savingName);
		
		fprintf(plannedsavings,"+---------------------------------------+-----------------------+\n");
		fprintf(plannedsavings,"|                MONTH                  |         AMOUNT    \t|\n");	
		fprintf(plannedsavings,"+---------------------------------------+-----------------------+\n");
		
		printf("TRANSACTION SUCCESSFUL!\n\n");
		printf("PLANNED SAVING REPORT\n\n");
		for(i=1;i<=month;i++){
			sum=saving;
			sum=saving+saving*interestTable(sum,month);
			summ+=sum;
			if(i%10==1 && i!= 11){
				   	fprintf(plannedsavings,"| %dst month savings amount\t\t| Rp. %lld,- \t|\n",i,summ);
				   	if(i==1){
						printf("Amount of savings earned per month: Rp. %lld,-\n",summ);
					}
				   	}
			else if (i%10==2 && i!= 12) fprintf(plannedsavings,"| %dnd month savings amount\t\t| Rp. %lld,- \t|\n",i,summ);
			else if (i%10==3 && i!= 13) fprintf(plannedsavings,"| %drd month savings amount\t\t| Rp. %lld,- \t|\n",i,summ);
			else if(i%12==0) fprintf(plannedsavings,"| %dth month (%d year) savings amount\t| Rp. %lld,- \t|\n",i,i/12,summ);
			else fprintf(plannedsavings,"| %dth month saving amount \t\t| Rp. %lld,- \t|\n",i,summ);
		}
		fprintf(plannedsavings,"+---------------------------------------+-----------------------+\n");
		fprintf(plannedsavings,"\n");
		printf("The amount of savings obtained according to the period of saving: Rp. %lld,-\n",summ);
		fclose(plannedsavings);
		FILE*transaction=fopen("Transaction Report.txt","a+");
		if (date->tm_mday == autodebetDay) {
        fprintf(transaction, "%s, %d-%d-%d\n", savingName, date->tm_mday, date->tm_mon + 1, date->tm_year + 1900);
    }
	fclose(transaction);
    	printf("\nDO YOU WANT TO DO ANOTHER TRANSACTION? (y/n): "); scanf(" %c",&again);
		system("cls");
    	break;
    case (3):
    	printf("PLANNED SAVINGS TRANSACTIONS CHECK\n\n");
    	printf("Enter the Saving Name: "); scanf(" %[^\n]",savingnamee);
    	system("cls");
    	transaction=fopen("Transaction Report.txt","r");
		   i=0;
		   printf("TRANSACTIONS:\n");
		   while(!feof(transaction)){
   			fscanf(transaction,"%[^\,], %d-%d-%d\n",trans[i].name,&trans[i].day,&trans[i].month,&trans[i].year);
		   	if(strcmp(trans[i].name,savingnamee)==0){
		   	check=1;
		   	printf("Saving Name: %s, auto debit has been done on %d-%d-%d\n",trans[i].name,trans[i].day,trans[i].month,trans[i].year);
		   }
		   i++;
		   }
		   if(check==0) printf("TRANSACTIONS BASED ON THE NAME OF THE PLANNED SAVINGS ARE NOT AVAILABLE!\n");
		   printf("\nDO YOU WANT TO DO ANOTHER TRANSACTION? (y/n): "); scanf(" %c",&again);
			system("cls");
		break;		
    case (4):
		goto labelend;
    default:
    	printf("INVALID CHOICE!\n\n");
    	goto labelinvalid;
	}
}
	labelend:	
	fflush(stdin);
	printf("Exit...\n");

	return 0;
}



