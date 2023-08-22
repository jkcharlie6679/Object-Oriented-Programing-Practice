#include <fstream>
#include <iostream>

using namespace std;

class Point2D
{
private:
  int x;
  int y;
public:
  Point2D()
  {
    x = 0;
    y = 0;
  }
  bool operator>(const Point2D &p)
  {
    return (x > p.x) || (x == p.x && y > p.y);
  }
  Point2D &operator=(const int &k)
  {
    x = k;
    y = k;
    return *this;
  }
  void setX(int x)
  {
    this->x = x;
  }
  void setY(int y)
  {
    this->y = y;
  }
  friend ostream &operator<<(ostream &out, const Point2D &p);
};

ostream &operator<<(ostream &out, const Point2D &p)
{
  out << "(" << p.x << "," << p.y << ")";
  return out;
}

template <class T>
T *new1D(int n, int k)
{
  T *vec = new T [n];
  for (int i = 0; i < n; i++)
    vec[i] = k;
  return vec;
}

template <class T>
void delete1D(T *vec)
{
  assert(vec != NULL);
  delete [] vec;
}

template <class T>
void display1D(T *vec, int n)
{
  for (int i=0;i<n;i++)
    cout << vec[i] << " ";
  cout << endl;
}

template <class T>
void rand1D(T *vec, int n)
{
  for (int i=0;i<n;i++)
    vec[i] = rand() % 10 + (double) (rand() % 10) / 100;
}

template <>
void rand1D(char *vec, int n)
{
  for (int i=0;i<n;i++)
    vec[i] = rand() % 10 + 'a';
}

template <>
void rand1D(Point2D *vec, int n)
{
  for (int i=0;i<n;i++)
  {
    vec[i].setX(rand() % 10);
    vec[i].setY(rand() % 10);
  }
}

template <class T>
void sort1D(T *vec, int n)
{
  for (int i=0;i<n-1;i++)
    for (int j=i+1;j<n;j++)
      if (vec[i] > vec[j])
      {
        T temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
      }
}

template <class T>
void display(T *vec, int n)
{
  for (int i=0;i<n;i++)
    cout << vec[i] << " ";
  cout << endl;
}

template<class T>
void analysis(int n, int k = 0)
{
  T *vec = new1D<T> (n, k);
  rand1D<T>(vec, n);
  display1D<T>(vec, n);
  sort1D<T>(vec, n);
  display<T>(vec, n);
}

int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;
  srand(1);

  analysis<int>(n);
  analysis<double>(n);
  analysis<char>(n);
  analysis<Point2D>(n);

  return 0;
}

