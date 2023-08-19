#ifndef MATRIX_H
#define MATRIX_H

class Mtx
{
protected:
  int dim;
public:
  virtual int &operator() (int i, int j) = 0;
  virtual const int &operator() (int i, int j) const = 0;
  virtual void showMatrix () const = 0;
  virtual ~Mtx () {}
};

class FullMatrix: public Mtx
{
private:
  int **matrix;
public:
  FullMatrix (int n);
  int &operator() (int i, int j);
  const int &operator() (int i, int j) const;
  void showMatrix () const;
  ~FullMatrix ();
};

class SymmetricMatrix: public Mtx
{
private:
  int **matrix;
public:
  SymmetricMatrix (int n);
  int &operator() (int i,int j);
  const int &operator() (int i,int j) const;
  void showMatrix() const;
  int &getElem (int i, int j) const;
  ~SymmetricMatrix ();
};

class LowTriMatrix: public SymmetricMatrix
{
public:
  LowTriMatrix (int n);
  int &operator() (int i,int j);
  const int &operator() (int i,int j) const;
  void showMatrix () const;
};

class UpperTriMatrix : public SymmetricMatrix
{
public:
  UpperTriMatrix (int n);
  int &operator() (int i,int j);
  const int &operator() (int i,int j) const;
  void showMatrix () const;
};

#endif // MATRIX_H
