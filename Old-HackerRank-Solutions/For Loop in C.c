#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
for(int n=a;n<=b;n++){
    if (n>=1 && n<=9) {
        char* words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
         printf("%s\n", words[n-1]);
    } else if (n>9 && n%2==0){
        printf("even\n");
    }else if (n>9 && n%2!=0 ){
        printf("odd\n");
    }else{
        printf("null\n");
    }

    
}


    return 0;
}

