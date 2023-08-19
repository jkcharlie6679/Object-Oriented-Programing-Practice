#ifndef MATRIX_H
#define MATRIX_H

namespace matrix {
  class Matrix {
  private:
    int n;
    int **elements;
  public:
    Matrix();
    void assignDimension(int n);
    void assignElements();
    void assignMatrix(Matrix A);
    void transposeMatrix();
    void printMatrix();
    Matrix addMatrix(Matrix B);
    Matrix subtractMatrix(Matrix B);
    Matrix multiplyMatrix(Matrix B);
  };
}

#endif

