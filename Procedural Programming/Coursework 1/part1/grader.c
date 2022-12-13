
/*
 * Template file for the solution to part 1
 * Use the included print statements in your code at appropriate times.
 * Do not adjust the format of the print statements.
 * Do not submit a final solution with additional print statements.
 */

#include <stdio.h>
#include <stdlib.h>


int main( int argc, char **argv ) { //strtok is like string.split !!! 

  if(argc < 2){
    printf("No input file name given. Exiting.\n");
    return -1;
  }

  // declare file pointer
  FILE *fileread;

  // open file for reading
  printf("Input file. Opening.\n");
  fileread = fopen(argv[1], "r"); 

  // check if file exists or can be opened 
  if(fileread == NULL){
    printf("Input file does not exist. Exiting.\n");
    return -1;
  }
  
  // statically allocated 2d array 
  int array[32][5];

  // iteratively read from grades.txt file and append to array
  for(int i = 0; i < 32; i++){ //help
    fscanf(fileread, " %d %d %d %d %d ", &(array[i][0]), &(array[i][1]), &(array[i][2]), &(array[i][3]), &(array[i][4])); 
    printf("%d | %d, \n", array[i][0], array[i][2]); 

  }
  
  //closing input file
  printf("Input file. Closing.\n");
  fclose(fileread);

  // data processing
  printf("Checking data.\n");

  // checking for valid student id
  int id;

  for(int i = 0; i < 32; i++){
    id = array[i][0];
    if (id < 2022000 || id > 2022099){
      printf("Found an invalid student id: %d. Exiting.\n",id); // requires student id
      return -1;
    }
  }

  // placeholder vars calulating and appending averages into new array 
  int grade;

  for(int i = 0; i < 32; i++){
    // reassign id for each entry
    id = array[i][0];
    // iterate through grade values
    for(int k = 1; k < 5; k++){ 
      
      // assign array reference to readable identifier
      grade = array[i][k];

      // invalid grade check
      if(grade < 0 || grade > 100){
        printf("Found an invalid grade: id %d grade %d. Exiting.\n", id,grade );
        return -1; 
      }

      // grade correction checks
      if(grade < 20){
        printf("Correcting student %d grade %d\n",id,grade);
        grade = 20; 
      }
      else if(grade > 90){
        printf("Correcting student %d grade %d\n",id,grade);
        grade = 90; 
      }
    }
  }

  // compute averages
  printf("Computing averages.\n");

  // declare new array to store ids and averages
  int array_average[32][2]; 

  //copying student ids into new array 
  for(int i = 0; i < 32; i++){
    array_average[i][0] = array[i][0];
  }

  int sum;
  
  for(int i = 0; i < 32; i++){
    sum = 0; // reset sum for each new entry   
    for(int k = 1; k < 5; k++){
      sum = sum + array[i][k];
    }
    // formula ensures mathematically rounded
    array_average[i][1] = (sum + 2) / 4;
  }
  
  // writing to file
  FILE *filewrite;

  //open connection to averages.txt
  printf("Output file. Opening.\n");
  filewrite = fopen("averages.txt", "w");

  //iteratively append output array to file row-by-row
  for(int i = 0; i < 32; i++){
      fprintf(filewrite, "%d %d\n", array_average[i][0], array_average[i][1]);
  }
  
  printf("Output file. Closing.\n");
  fclose(filewrite); 
  
  return 0;
}

