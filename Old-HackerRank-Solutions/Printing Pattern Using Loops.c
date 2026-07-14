#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            int min_i=i<2*n-1-i+1?i:2*n-1-i+1;
            int min_j=j<2*n-1-j+1?j:2*n-1-j+1;
            int min_dist=min_i<min_j?min_i:min_j;
            printf("%d ",n-min_dist+1);
        }printf("\n");
    }
    return 0;
}
