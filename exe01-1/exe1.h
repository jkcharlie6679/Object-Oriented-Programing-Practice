
#ifndef exe1_h
#define exe1_h
typedef struct {
  double real;
  double image;
} Cplex;

void ReadTextFile(char *filename, Cplex &a, Cplex &b);
Cplex ComplexOperation(Cplex &a, Cplex &b, char op);
void PrintComplex(char *filename, Cplex *res);
#endif

