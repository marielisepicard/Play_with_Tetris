# 🟦 Play with Tetris

## Algoritmic project to fit Tetris pieces into a box, using recursive backtracking. 

The goal is to find the optimal way to fit Tetriminos (Tetris pieces), without rotation. 

[📌 Subject (in French 🇫🇷)](https://cdn.intra.42.fr/pdf/pdf/5910/fillit.fr.pdf) 

Getting the ***optimal solution among a large number of possibilities*** is a classic programming problematic. We also need to find it in an ***reasonable amount of time***.

The program takes a map of Tetriminos (maximum 26 blocks) and display the solution.

--------

***map example:***

```
...#$
...#$
...#$
...#$
$
....$
....$
....$
####$
$
.###$
...#$
....$
....$
$
....$
..##$
.##.$
....$
$
....$
.##.$
.##.$
....$
$
....$
....$
##..$
.##.$
$
##..$
.#..$
.#..$
....$
$
....$
###.$
.#..$
....$
```

***solution (each Tetriminos is depicted with its own letter):***
```
ABBBB.$
ACCCEE$
AFFCEE$
A.FFGG$
HHHDDG$
.HDD.G$

```

--------

## 👌🏻 To play with it:

```
git clone https://github.com/marielisepicard/Play_with_Tetris.git
make 
./fillit map
```

