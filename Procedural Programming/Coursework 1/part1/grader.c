
/*
 * Template file for the solution to part 1
 * Use the included print statements in your code at appropriate times.
 * Do not adjust the format of the print statements.
 * Do not submit a final solution with additional print statements.
 */

#include <stdio.h>

int main( int argc, char **argv ) { //strtok is like string.split !!! 


  // student id, g1, g2, g3, g4
  // id must be in range 2022000 to 2022099 

  // declare file pointer
  FILE *fp; 

  // open file for reading
  printf("Input file. Opening.\n");
  fp = fopen("grades.txt", "r"); 

  // check if file exists or can be opened 
  if(fp == NULL){
    printf("No input file name given. Exiting.\n");
    return -1; 
  }


  

  

  int id, grade_1, grade_2, grade_3, grade_4, average;
  id = 2; 
  const char space[2] = " ";
  char *tok;
  /*
  for(int i = 0; i < 32; i++){
      char line[30] = //readline
      
      tok = strtok(line, space); 

      while(tok != NULL){
        printf("%s\n", tok); 
        tok = strtok(NULL, space); 
        
      }
      // split textfile line
      

      // reassign argument as valuabls 
      

    }

  */
  // iterate through known number of entries [32]
  

  printf("Input file. Closing.\n");
  fclose(fp); 

  /*
  if(id < 2022000 || id > 2022099){
    printf("Found an invalid student id: %d. Exiting.\n",id); // requires student id
    return -1; 
  }

  if(grade[k] < 0 || grade[k] > 100){
    printf("Found an invalid grade: id %d grade %d. Exiting.\n", id,grade );
    return -1; 
  }
  */
  


  // command line arguments
  
  printf("Input file does not exist. Exiting.\n");
  
  // reading from file
  printf("Input file. Opening.\n");
  printf("Input file. Closing.\n");

  // data processing
  printf("Checking data.\n");
  
  //printf("Found an invalid grade: id %d grade %d. Exiting.\n", id,grade ); // requires student id and relevant grade
  //printf("Correcting student %d grade %d\n",id,grade); // requires student id and relevant grade

  // compute averages
  printf("Computing averages.\n");

  // writing to file
  printf("Output file. Opening.\n");
  printf("Output file. Closing.\n");

  return 0;
}

