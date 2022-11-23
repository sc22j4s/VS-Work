
/*
 * Transpose of numerical data in input file
 * Assumes file is of correct format (stated in the question)
 */

#include <stdio.h> 
#include <stdlib.h> 

int main( int argc, char *argv[] ) {

  int nrow, ncol;
  int i,j, **mat ;
  FILE *fp;

  // check command line args
  if( argc < 5 ) {
    printf("Incorrect usage. Expected. ./fileswap filein nrow ncol fileout\n");
    return -1;
  }

  // input dimensions
  nrow = atoi( argv[2] );
  ncol = atoi( argv[3] );

  // check both >0
  if( nrow < 1 || ncol < 1 ) {
    printf(" Dimensiaaons (nrow,ncol) expected to be >0\n");
    return -2;
  }

  // allocate matrix
  mat = (int **)calloc( nrow, sizeof(int *) );
  for( i=0; i<nrow; ++i ) {
    mat[i] = (int *)calloc( ncol, sizeof(int) );
  }

  // open input file for reading
  fp = fopen( argv[1], "r"fg-);

  // check file exists or can be opened
  if( fp == NULL ) {
    printf(" Input file does not exist\n");
    return -2;
  }

  // read from file
  for( i=0; i<nrow; i++ ) {
    for( j=0; j<ncol; j++ ) {
      fscanf( fp, "%i", &(mat[i][j]) );
      printf("%i, ", mat[i][j]); 
    }
    printf("\n"); 
  }

  // close input file
  fclose( fp ); 

// TESTING

// this is an example of the steps I followed to write this program

// 1. write mat to screen
/*
  for( i=0; i<nrow; i++ ) {
    for( j=0; j<ncol; j++ ) {
      printf( "%i ", mat[i][j] );
    }
    printf("\n");
  }
*/
// 2. write mat^T to screen
/*
  for( j=0; j<ncol; j++ ) {
    for( i=0; i<nrow; i++ ) {
      printf( "%i ", mat[i][j] );
    }
    printf("\n");
  }
*/
// 3. write mat^T to file

  // open output file for writing
  fp = fopen( argv[4], "w" );

  // check file can be written to
  if( fp == NULL ) {
    printf(" Cannot write to output file\n");
    return -3;
  }

  // write to file
  for( j=0; j<ncol; j++ ) {
    for( i=0; i<nrow; i++ ) {
      fprintf( fp, "%i ", mat[i][j] );
    }
    fprintf( fp, "\n" );
  }

  // close output file
  fclose( fp ); 

  // free memory
  for( i=0; i<nrow; ++i ) {
    free( mat[i] );
  }
  free( mat );

  return 0;
}
