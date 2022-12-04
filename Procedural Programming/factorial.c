#include <stdio.h>

int main(void){
    
    int num = 4;
    int sum = 1; 
    for(int i = 2; i <= num; i++){
        sum = sum * i; 
    }

    printf("Factorial of %i\n ", num);
    printf("is %i\n ", sum); 
}   