# This is corewar project of 42 ecole methodology
About
-----

>Core War is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called "warriors") compete for control of a virtual computer.
These battle programs are written in an abstract assembly language called Redcode.


To launch you need clang installed, project optimized for macOS Mojave

to compile run make

##### How to use it ?

* First you'll need to write a .s file with a set of assembly instructions
    * You can find this set in either [corewar.pdf](https://raw.githubusercontent.com/kcosta42/Corewar/master/corewar.pdf) or in [corewar_en.pdf](https://raw.githubusercontent.com/kcosta42/Corewar/master/corewar_en.pdf)
    * Or you can just use one of the many warriors in the resources/champions directory
* Then you'll have to compile it using the `asm` binary
* Then just execute the `corewar` binary with your warrior(s) as arguments