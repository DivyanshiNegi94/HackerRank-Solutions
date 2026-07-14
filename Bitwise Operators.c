#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
 int max_and=0,max_or=0,max_xor=0;
  for(int a=1;a<n;a++){
    for(int b=a+1;b<=n;b++){
      int c_and=a&b;
      int c_or=a|b;
      int c_xor=a^b;  
    if(c_and<k && c_and>max_and)max_and=c_and;
    if(c_or<k && c_or>max_or)max_or=c_or;
    if(c_xor<k && c_xor>max_xor)max_xor=c_xor;
    
    
  }
}printf("%d\n%d\n%d",max_and,max_or,max_xor);
}
int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
