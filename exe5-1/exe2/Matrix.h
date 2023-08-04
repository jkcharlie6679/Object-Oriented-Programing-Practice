#ifndef MATRIX_H
#define MATRIX_H

namespace matrix {
  class Matrix {
  private:
    int n;
    int **elements;
  public:
    Matrix();
    Matrix(int n);
    Matrix(const matrix::Matrix &m);
    ~Matrix();
    void assignDimension(int n);
    void assignElements();
    void assignMatrix(Matrix A);
    void transposeMatrix();
    void printMatrix();
    void addMatrix(Matrix A, Matrix B);
    void subtractMatrix(Matrix A, Matrix B);
    void multiplyMatrix(Matrix A, Matrix B);
  };
}

#endif

