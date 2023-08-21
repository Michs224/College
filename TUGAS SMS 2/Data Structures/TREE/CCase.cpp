#include <stdio.h>
#include <string.h>

int main(){
    long unsigned int N;
    scanf("%ld",&N);
    char a[N],b[N];
    scanf("%s",a);
    scanf("%s",b);
    int count=0;
    for(long unsigned int i=0;i<N;i++){
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