# BIG NUMBER OPERATION

Big Number calculation is frequently seen while dealing with a large number. For example, there is no built-in data type can store a number with 100 digits. To solve the problem, you have to write a program to process the large number digit-by-digit and store digits in an integer array.

You have to process input file "bignumber.txt" to obtain two big numbers and output the results of arithmetic operations to "result.txt".

The command-line usage of the program is shown below

```shell
./ex2-2 bignumber.txt result.txt
```

The required format for a sample input file “ex2-2.in” as “bignumber.txt” is shown below. In the “bignumber.txt” file, the first line and the second line indicate the big number A and B, respectively.

```text
12443
5467755
```


Your result should be written to a user-specified output file. The sample output for "ex2-2.in" is file "ex2-2.out" with the content shown as below.

```text
5480198 // A + B
-5455312 // A - B
```

## Requirement

```cpp
typedef struct
{
  int *data;
  int length;
  bool sign;
} BIGNUMBER;

int main(int argc, char *argv[])
{
  BIGNUMBER a, b;
  ReadTextFile(argv[1], a, b);
  BIGNUMBER results[2];
  results[0] = BigNumberOperation(a,b,'+');
  results[1] = BigNumberOperation(a,b,'-');
  WriteResults(argv[2], results);
  return 0;
}
```

You have to finish this exercise using the above structure and three more functions of your own: ReadTextFile(), BigNumberOperation() and WriteResults().


## Reference

[NYCU OCW Object-Oriented Programming Lab 02](https://ocw.nycu.edu.tw/course/oop002/LAB_02.pdf)

