
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Roots of a quadratic:  a x^2 + b x + c = 0
 * 0, 1 or 2 roots exist 
 *
 * Note
 * The value of d will not usually be d==0.0
 * Floating point arithmetic is not that precise
 * A float has about 8 decimal places of accuracy so we test for "nearly zero"
 */

int main( int argc, char *argv[] ) {

  float a,b,c,d; 
  float root1, root2; 

  // test we have enough command line data
  if( argc < 4 ) {
    printf(" Error: Usage:  ./quadratic3 a b c\n");
    return -1;
  }

  // convert 3 command line arguments to float (expected values)
  a = atof( argv[1] );
  b = atof( argv[2] );
  c = atof( argv[3] );

  printf(" Solutions for: (%5.2f) x^2 + (%5.2f) x + (%5.2f) = 0\n",a,b,c);

  d = b*b - 4.0*a*c; // we compute this first as we must test it

  // logical tests for the 3 cases: d<0, d=0, d>0
  
  if( d < 0.0 ) {  // d<0 -> no roots
    printf("0 roots\n");
  }
  else if( fabs(d) < 1.0e-7 ) {  // d close to zero (<1e-7) -> one root
    root1 = -0.5*b/a;  // expression for the 1 root

    printf("1 root: %8.3f\n", root1 );
  }
  else { // d>0 -> two roots
    root1 = 0.5*( -b + sqrt(d) )/a;  // expression for the 2 roots
    root2 = 0.5*( -b - sqrt(d) )/a;

    printf("2 roots: %8.3f %8.3f\n", root1,root2 );
  }
  
  return 0;
}

