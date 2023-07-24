# COMPLEX ARITHMETIC

Please write a C++ program to operate the arithmetic of complex number. You have to read two complex numbers from “complex.txt.” and output the arithmetical result of the two complex numbers to “result.txt.” The example files content are as follow.

The command-line usage of the program is shown below

```shell
>./pg01 complex.txt result.txt
```

The required format for a sample input file as “complex.txt” is shown as follows.

```text
1.5+6i
-2-10i
```

In the “complex.txt” file, the first line and the second line indicates the complex number A and B, respectively. The representation of complex number is a+bi, where a means the real part and b means the image part. If a is equal to zero, it can be written as 0+bi instead of bi. For the same reason, it should be written as a+0i while the complex number has no image part.


Your result should be written to user-specified output file. The sample output file with the content shown as below.

```txt
-0.500–4.000i // A + B
3.500+16.000i // A - B
57.000–27.000i // A * B
-0.606+0.029i // A / B
```

### Requirement

In this exercise, you need to extract information from the given text file. To process a text file, you have to observe the format of this text file first. For example, each line indicates a complex number, there is no space in the line, and the numbers are separated by ‘+’, ‘-’ and ‘i’.

```cpp
int main(int argc, char *argv[])
{
  Cplex a, b; // use struct named Cplex under namespace Complex
  ReadTextFile(argv[1], a, b); // process text file
  Cplex results[4]; // store the results of diff. operation
  results[0] = ComplexOperation(a, b, ’+’);
  results[1] = ComplexOperation(a, b, ’-’);
  results[2] = ComplexOperation(a, b, ’*’);
  results[3] = ComplexOperation(a, b, ’/’);
  PrintComplex(argv[2], results); // print the results on file.
  return 0;
}
```

You have to finish this exercise by above structure and write three functions: ReadTextFile(),
ComplexOperation() and PrintComplex().

## Reference

[NYCU OCW Object-Oriented Programming Lab 01](https://ocw.nycu.edu.tw/course/oop002/LAB_01.pdf)


