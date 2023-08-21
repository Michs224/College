#include <stdio.h>
#include <string.h>
char *printCode(char string[]){
    int repetitions=0;
    int stringStart;
    int i=0;
    int brackets=1;
	
    while(string[i]<'0'||string[i]>'9'){
        if(string[i]=='\0') return &string[i];
        printf("%c",string[i]);
        i++;
    }
    for(i;string[i]!='[';i++){
        repetitions*=10;
        repetitions+=(string[i]-'0');
    }
    printf("%d\n",i);
    stringStart=i+1;
    for(i=stringStart;brackets!=0;i++){
        if(string[i]=='[') brackets++;
        if(string[i]==']') brackets--;
    }
    int stringEnd=i-2;
    for(i=0;i<repetitions;i++){
        for(int j=stringStart;j<=stringEnd;j++){
            if(string[j]>='0'&&string[j]<='9'){
                char *temp = printCode(&string[j]);
                int difference = temp - &string[j];
               j+=difference-1;
                continue;
            }
            printf("%c",string[j]);
        }
    }
//    printf("\n");
    
    int codeEnd=stringEnd+2;
//    char tamp[31]={NULL};
//    int k=0;
//    for(int i=codeEnd;string[i]!=NULL;i++){
//    	tamp[k]=string[i];
//    	k++;
//	}
//	for(int i=0;tamp[i]!=NULL;i++){
//		printf("%c",tamp[i]);
//	}
    return &string[codeEnd];
}


int main(){
//char str[] = "ini adalah contoh string";
//char *result = strstr(str, &str[9]);
//char hh[31];
//char *hhr=result;
//
//printf("%s\n", hhr); // output: contoh string
    int testcases;
    scanf(" %d",&testcases);
    for(int i=0;i<testcases;i++){
        char string[31];
        scanf(" %[^\n]",string);
        printf("Case #%d: ",i+1);
        char *temp;
        temp = printCode(string);
        
        while(*temp!='\0'){
            temp = printCode(temp);
        }
        puts("");
    }
}
