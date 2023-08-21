#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct movie{
	char judul[101];
	char genre[36];
	char studio[51];
	int tahun;
	struct movie *next;
};

struct movie registermovie(struct movie data);

void search1(struct movie *head,struct movie data){
	if(head==NULL){
		printf("\n");
		printf("                      Film Tidak Ditemukan\n\n\n");
		system("pause");
	}else{
		do{
			if(strcmp(head->judul,data.judul)==0 && strcmp(head->genre,data.genre)==0
			&& strcmp(head->studio,data.studio)==0 && head->tahun==data.tahun){
				printf("\n");
				printf("                      Film Ditemukan\n");
				printf("                      Judul  : %s\n",head->judul);
				printf("                      Genre  : %s\n",head->genre);
				printf("                      Studio : %s\n",head->studio);
				printf("                      Tahun  : %d\n\n",head->tahun);
				system("pause");
				return;
			}
			
			head = head->next;
		}while(head!=NULL);
		printf("\n");
		printf("                      Film Tidak Ditemukan\n\n\n");
		system("pause");
		
	}
}

void delete1(struct movie **head,struct movie data){
    struct movie *head1=*head,*ptr;
    if(head1==NULL){
        printf("\n");
        printf("                      Film Tidak Ditemukan/tidak Ada\n\n\n");
        system("pause");
    }else{
        ptr = NULL;
        do{
            if(strcmp(head1->judul,data.judul)==0 && strcmp(head1->genre,data.genre)==0
            && strcmp(head1->studio,data.studio)==0 && head1->tahun==data.tahun){
                printf("\n                      Film yang akan dihapus adalah: \n");
                printf("                      Judul  : %s\n",head1->judul);
                printf("                      Genre  : %s\n",head1->genre);
                printf("                      Studio : %s\n",head1->studio);
                printf("                      Tahun  : %d\n\n",head1->tahun);
                printf("                      The movie has been successfully deleted\n\n");
                system("pause");
                if(ptr == NULL){
                    *head = head1->next;
                }else{
                    ptr->next = head1->next;
                }
                free(head1);
                break;
            }
            ptr = head1;
            head1 = head1->next;
        }while(head1!=NULL);
        if(head1==NULL){
            printf("\n                      Film Tidak Ditemukan/tidak Ada\n\n\n");
            system("pause");
        }
    } 
}


int tablehash(struct movie data){
	fflush(stdin);
	int total=0;
	
	for(int x=0; x<strlen(data.judul); x++){
		total += data.judul[x];
	}
	
	total += data.genre[0];
	
	for(int x=0; x<strlen(data.studio); x++){
		if(x==0){
			total += data.studio[x];
		}else if(data.studio[x]==32){
			total += data.studio[x+1];
		}
		
	}
	
	data.tahun %= 100;
	total += data.tahun;

	return total %= 10;
}

void insert(struct movie **head,char judul[],char genre[],char studio[],int tahun,int table){
	struct movie *temp = (struct movie*) malloc(sizeof(struct movie));
	
	strcpy(temp->judul,judul); strcpy(temp->genre,genre); strcpy(temp->studio,studio);
	temp->tahun=tahun;
	
	temp->next = *head;
	*head = temp;
	
}


int main(){
	struct movie *head[10],data;
    for (int i = 0; i < 10; i++) {
        head[i] = NULL; 
    }
	int pilihan=1,table=0;
	char key,menu[5][35]={"Insert Movie","Search Movie","Delete Movie","Exit"};
	while(1){
		//fflush(stdin);
		printf("\033[2J"); 
      	printf("\033[0;0H"); 
		system("cls");
		char s[35]={"Welcome To Movie BINUS"};
		printf("\n                                              \033[36;4;6m%s\033[0m",s);
		
		switch(pilihan){
			case 1:
				printf("\n\n");			
				printf("                                                1.  \033[3;7m%s\033[0m\n",menu[0]);
				printf("%64s\n",menu[1]);
				printf("%64s\n",menu[2]);
				printf("%60s\n",menu[3]);
				break;
			case 2:
				printf("\n\n");
				printf("%64s\n",menu[0]);
				printf("                                                2.  \033[3;7m%s\033[0m\n",menu[1]);
				printf("%64s\n",menu[2]);
				printf("%60s\n",menu[3]);
				break;
			case 3:
				printf("\n\n");
				printf("%64s\n",menu[0]);
				printf("%64s\n",menu[1]);
				printf("                                                3.  \033[3;7m%s\033[0m\n",menu[2]);
				printf("%60s\n",menu[3]);
				break;
			case 4:
				printf("\n\n");
				printf("%64s\n",menu[0]);
				printf("%64s\n",menu[1]);
				printf("%64s\n",menu[2]);
				printf("                                                        \033[3;7m%s\033[0m\n",menu[3]);
				break;
		}
		
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\033[35;0mArrow key [down | up] to move                                                                            Enter to choose\033[0m");
		key=getch();
		switch(key) {
         case 72:
         	printf("\033[2J"); // membersihkan layar
      printf("\033[0;0H"); // mengatur cursor ke posisi 0,0
            if(pilihan > 1) {
               pilihan--;
            }else if(pilihan == 1){
            	pilihan=4;
			}
            break;
         case 80: 
         printf("\033[2J"); // membersihkan layar
      printf("\033[0;0H"); // mengatur cursor ke posisi 0,0
            if(pilihan < 4) {
               pilihan++;
            }else if(pilihan == 4 ){
            	pilihan = 1;
			}
            break;
         case 13:
		 	printf("\033[2J"); 
      		printf("\033[0;0H"); 
            if(pilihan==1){
            	system("cls");
            	data=registermovie(data);
            	table=tablehash(data);
            	insert(&head[table], data.judul, data.genre, data.studio, data.tahun, table);
				printf("\n\n                   The movie has been successfully added\n\n");
				system("pause");
			}else if(pilihan==2){
				system("cls");
				data=registermovie(data);
				table=tablehash(data);
				search1(head[table],data);
			}else if(pilihan==3){
				system("cls");
				data=registermovie(data);
				table=tablehash(data);
				delete1(&head[table],data);
			}else if(pilihan==4){
            	return 0;
			}
            break;
        }
	}
}

struct movie registermovie(struct movie data){
	printf("\n");
	printf("                      Input Name Film: ");
	gets(data.judul);
	printf("                      Input Name Genre: ");
	gets(data.genre);
	printf("                      Input Name Studio: ");
	gets(data.studio);
	printf("                      Input Tahun: ");
	scanf("%d",&data.tahun);
	
	return data;
}