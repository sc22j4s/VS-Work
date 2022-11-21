
#include <stdio.h>

/*
 * Complete the code so that 3 command line values are given defining a quadratic equation.
 *   a x^2 + b x + c = 0
 * Find the roots of the equation and display the results
 *
 * Do not alter the print statements - the autograder expects them
 * You should use them at appropriate places in your program 
 */

int main( int argc, char *argv[] ) {

  // the code requires command line values for coefficients a,b,c 
  // print this error and exit if not 
  printf(" Error: Usage:  ./quadratic3 a b c\n");

  // display the equation using the provided coefficients
  printf(" Solutions for: (%5.2f) x^2 + (%5.2f) x + (%5.2f) = 0\n",a,b,c);

  // when there are 0 roots
  printf("0 roots\n");

  // when there is 1 root
  printf("1 root: %8.3f\n", root1 );

  // when there are 2 roots
  printf("2 roots: %8.3f %8.3f\n", root1,root2 );

  return 0;
}
