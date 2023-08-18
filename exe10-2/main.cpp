#include <iostream>
#include "school.h"

using namespace std;

int main(int argc, char **argv)
{
  school nctu(argv[1]);
  nctu.report(argv[2]);
  return 0;
}

