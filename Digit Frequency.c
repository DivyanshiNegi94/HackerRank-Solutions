#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
char *num=(char *)malloc(1001* sizeof(char)) ;
int freq[10]={0};
if (num==NULL){
    return 1;
}
scanf("%1000[^\n]", num);
for (int i=0;num[i]!='\0';i++){
    if(num[i]>='0'&&num[i]<='9'){
        int index=num[i]-'0';
        freq[index]++;
    }
}for (int i=0;i<10;i++){
    printf("%d ",freq[i]);
}
printf("\n");
free(num);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
