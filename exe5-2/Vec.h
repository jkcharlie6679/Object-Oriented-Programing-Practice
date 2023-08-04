

#ifndef VEC_H
#define VEC_H

class Vec
{
private:
  int *array;
  int dim;
public:
  Vec();
  Vec(int *array, int dim);
  // ~Vec();
  void assign(int *array, int dim);
  void printVec();
  void sort();
  bool isEqual(Vec vec);
  void unionSet(Vec vec1, Vec vec2);
  Vec inpendetSet();
  int min();
  int max();
  bool find(int target);
};

#endif // VEC_H

