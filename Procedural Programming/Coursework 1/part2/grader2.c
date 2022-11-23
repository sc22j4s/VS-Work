
#include <stdio.h>

int main( int argc, char **argv ) {

  // check for sufficient arguments
  if(argc < 4){
    printf("Incorrect arguments given. Expecting nStudents nGrades fileName. Exiting.\n");
    return -1;
  }

  // convert arguments to dimensions of array 
  int row_count = atoi(argv[1]); // number of students
  int col_count = atoi(argv[2]); // number of grades

  if(row_count < 1 || row_count > 100){
    printf("Requires 1 to 100 students. Exiting.\n");
    return -1; 
  }
  
  if(col_count < 1 || col_count > 8){
    printf("Requires 1 to 8 grades. Exiting.\n");
    return -1;
  }

  // including the student ids as part of the array
  // additional column required 
  col_count = col_count + 1; 

  char *filename;
  // allocates minimal memory to variable 'filename'
  int arg_length = strlen(argv[3]);
  filename = (char *)malloc(arg_length * sizeof(filename));
  filename = argv[4];


  // accessing file
  printf("Input file. Opening.\n");
  FILE *fp;
  fp = fopen(filename, "r");

  // check if file is available
  if(fp == NULL){
    printf("Input file does not exist. Exiting.\n");
    return -1;
  }

  // dynamic allocation of 2d input array
  int **array;

  array = (int **)calloc(row_count, sizeof(int *));
  for(int i = 0; i < row_count; i++){
    array[i] = (int *)calloc(col_count, sizeof(int));
  }

  // read each number from file into 2d array
  for(int i = 0; i < row_count; i++){
    for(int k = 0; k < col_count; k++){
      fscanf(fp, "%i ", &(array[i][k]));
    }
  }
  
  printf("Input file. Closing.\n");
  fclose(fp); 

  printf("Checking data.\n");

  // checking for valid student id
  int id;

  for(int i = 0; i < row_count; i++){
    id = array[i][0];
    if (id < 2022000 || id > 2022099){
      printf("Found an invalid student id: %d. Exiting.\n",id); // requires student id
      return -1;
    }
  }

  // placeholder vars calulating and appending averages into new array 
  int grade;

  for(int i = 0; i < row_count; i++){
    // reassign id for each entry
    id = array[i][0];
    // iterate through grade values
    for(int k = 1; k < col_count; k++){ 
      
      // assign array reference to readable identifier
      grade = array[i][k];

      // if failed, execute invalid grade check
      if((grade < 0 || grade > 100) && grade != -1){
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

  // dynamic allocation of 2d output array
  int **array_average;

  // output array known to only need 2 columns 
  array_average = (int **)calloc(row_count, sizeof(int *)); 
  for(int i = 0; i < row_count; i++){
    array[i] = (int *)calloc(2, sizeof(int)); 
  }

  int sum;

  for(int i = 0; i < row_count; i++){
    sum = 0; // reset sum for each new entry  
    for(int k = 1; k < 5; k++){
      sum = sum + array[i][k];
    }
    // formula ensures mathematically rounded
    array_average[i][1] = (sum + 2) / 4;
  }

  // writing to file
  FILE *filewrite;

  // open connection to averages.txt
  printf("Output file. Opening.\n");
  filewrite = fopen("averages.txt", "w");

  // iteratively append output array to file row-by-row
  for(int i = 0; i < row_count; i++){
      fprintf(filewrite, "%d %d\n", array_average[i][0], array_average[i][1]);
  }

  printf("Output file. Closing.\n");
  fclose(filewrite);

  return 0;
}

