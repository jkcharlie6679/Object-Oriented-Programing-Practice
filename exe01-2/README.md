# DIFFERENTIATION OF POLYNOMIALS

Given an arbitrary polynomial with a degree n

$f(x) = c_nx^n + c_{n-1}x^{n-1} + ... + c_1x^1 + c_0$, $n$ and $c_i \in \mathbb{Z}, i \in [0,n]$

Please write a program to read a file containing a polynomial and find the differentiation of the polynomials. Write the result to the output file. In this example, n is less than 1000. The command-line usage of the program is shown below

```shell
>./ex02 input_file.in ouput_file.out
```

The required format for a sample input file is shown as follows.

```text
2X^2+X+1
```

Note that the representation of polynomial may not be in descending order. It can be X+1+2X^2 in above example.

Your result should be written to user-specified output file. The sample output for is file “ex02a.out” with the content shown as below.

```text
4X+1
```

## Requirement

The main function of your program is specific as follows,

```cpp
const int MAX = 1000;

typedef struct
{
  char coeff[10];
  int power;
} Items;

typedef struct
{
  Items items[MAX];
  int num_items;
} Poly;

int main(int argc, char *argv[])
{
  Poly eq;
  ReadTextFile(argv[1], eq); // process text file
  DifferentationPoly(eq); // differentiation of polynomials
  PrintComplex(argv[2], eq); // print the results on file.
  return 0;
}
```

## Reference

[NYCU OCW Object-Oriented Programming Lab 01](https://ocw.nycu.edu.tw/course/oop002/LAB_01.pdf)


