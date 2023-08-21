#include <stdio.h>
#include <string.h>

int main(){
    long unsigned int N;
    scanf("%d",&N);
    char a[N],b[N];
    scanf("%s",a);
    scanf("%s",b);
    int L,R;
    int count=0;
    for(int i=0;i<strlen(a);i++){
        if(a[i]>=b[i]) {

            i++;
            while(a[i]>=b[i]){
                i++;
            }

            count++;
        }
    }

    printf("%d\n",count);


    return 0;
}