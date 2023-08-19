#include "poly.h"

using namespace poly;


int main(int argc, char *argv[])
{
  Poly eq;
  ReadTextFile(argv[1], eq); // process text file
  DifferentationPoly(eq); // differentiation of polynomials
  PrintComplex(argv[2], eq); // print the results on file.
  return 0;
}

