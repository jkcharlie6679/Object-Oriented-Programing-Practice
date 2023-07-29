# CARD FLIPPING

Write a card flipping program. There are 36 cards and each card indicates one upper-case alphabet. The user has to gauss and memory the location of card until all cards are flipping. Notice that only two cards have the same alphabet and no daggling card is allowed here.

```text
>./ex3-2
* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *
Please enter card index: 0
G * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *
Please enter card index: 15
G * * * * *
* * * * * *
* * * H * *
* * * * * *
* * * * * *
Try Again!
* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *
Please enter card index: 19
* * * * * *
* * * * * *
* * * * * *
* H * * * *
* * * * * *
Please enter card index: 15
* * * * * *
* * * * * *
* * * H * *
* H * * * *
* * * * * *
Good Job!
Please enter card index: 10
* * * * * *
* * * R * *
* * * H * *
* H * * * *
* * * * * *
…
…
…
…
…
Please enter card index: 5
G B C E T Z
R Q P R D E
Z X A H P V
T H S G D S
A B Q V C X
Congratulation!!
```

You can design your own card flipping game. For example, decide the situation that the user enters the out-of-range number, design “exit” key to early end this game, or provide the hint to the user.

## Reference

[NYCU OCW Object-Oriented Programming Lab 03](https://ocw.nycu.edu.tw/course/oop002/LAB_03.pdf)

