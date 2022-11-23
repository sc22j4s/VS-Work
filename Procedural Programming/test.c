#include <stdio.h>

int main (int argc, char* argv[]) {
   FILE *fp; 
   printf("%s", argv[1]);
   fp = fopen(argv[1], "r"); 
   char string[40];
   const int nrow = 2; 
   const int ncol = 2; 
   int arr[2][2];

   for(int i = 0; i < 2; i++){
      fscanf(fp, "%i %i", arr[i][0], arr[i][1]); 
      printf("%i, %i", arr[i][0], arr[i][1]); 
   }
     

   return(0);

}
