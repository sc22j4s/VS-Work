
#include <stdio.h>

// print each command line argument

int main( int argc, char *argv[] ) {   // main accepts command line data as argc,argv
  int i;

  printf("%i", argc);

  // note that argc is always >=1 : the program name is stored in argv[0]
  
  for( i=1; i<argc; i++ ) {   // loop from 0<argc over all arguments given
    printf("%s\n",argv[i]);   // print each argument
  }
  printf("sedfg");

  return 0;
}
