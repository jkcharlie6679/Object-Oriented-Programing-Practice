#ifndef POLY_H
#define POLY_H

#define MAX 1000

namespace poly {
  typedef struct
  {
    int coeff;
    int power;
  } Items;
  
  typedef struct
  {
    Items items[MAX];
    int num_items;
  } Poly;

  void ReadTextFile(char *fileName, Poly &eq);
  void DifferentationPoly(Poly &eq);
  void PrintComplex(char *fileName, Poly &eq);
}

#endif

