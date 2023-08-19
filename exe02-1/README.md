# EVALUATION SYSTEM

Please write an evaluation system to analysis the student midterm online test for UEE1302 course. The evaluation system first reads the student scores from an input file, called “score.txt” and outputs the analysis results to file “result.txt”. The command-line usage of the evaluation system is

```shell
>./ex2-1 score.txt result.txt
```

In the input file “score.txt”, each row indicates a record for one student. As shown in the sample file “ex2-1.in”, the first and second columns denote the student’s ID and name, respectively. Since there are 9 problems in the online test, the students can select the problem set instead of writing every problem. However, the scores for different problems are different. The problems can be classified into the easy level, medium level and hard level. The first three problems are easy-level. If the student correctly answers one of easy-level problems, he/she can obtain 10 points. The next three problems are medium-level and 20 points are given for each one. The last three problems are hard-level and one can get 30 points for one correct answer. The full score is 100. The last column indicates the required time that the student returns the answer sheet.

```text
01 Tom 1 1 1 0 0 1 0 0 1 180
02 Jean 1 1 0 1 0 1 0 1 0 150
03 Kevin 0 0 0 1 0 1 0 1 1 90
04 John 1 0 0 0 0 0 1 1 1 70
05 Marry 1 1 1 1 1 1 1 0 0 150
```

The evaluation system needs to calculate the final score for every student and sort the results according to the final score and the required time. The list is sorted in a decreasing order depending on the final scores first. If two students have the same final scores, the student who requires less time has a higher rank. The sample output file “ex2-1.out” is shown as follows.

```text
04 John 100 70
03 Kevin 100 90
05 Marry 100 150
02 Jean 90 150
01 Tom 80 180
```

Note that you have to design the data structure called student to store the information for every student.

## Reference

[NYCU OCW Object-Oriented Programming Lab 02](https://ocw.nycu.edu.tw/course/oop002/LAB_02.pdf)

