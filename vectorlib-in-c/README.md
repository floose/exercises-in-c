# A Numerical Vector Library in C

**Introduction**

Inspired by some really good signal processing packages, mainly numpy and Octave sources, I decided to create my own functions for manipulating vectors in C. 

It is part of my own exercise on signal processing, as well an old attempt of creating a simulation environment for solving differential equations in microprocessors.

In the long run, it is part of a more ambitious project in which I intend to create my own hardware in the loop systems. 

**USE IT AT YOUR OWN RISK**

**Description**

* I this repo you will find the vectorLib.h and vectorLib.c containing the mathematical functions to deal with vectors;
* Vectors are the name of the structures that are manipulated by this code. They consist of a structure defined by a fixed **length**, a **name** and a **dynamic pointer** of the size of length. 
* Data is formatted in standard float;
* A main.c may change according to the examples I'm making to test the functions I designed;
* The updates to this repo may vary according to the time available in my work schedule.

## Makefile

To run the code, execute the commands on the Makefile. Credits to Nicomedes for their great Makefile creation tool ([link here](https://nicomedes.assistedcoding.eu/#/dashboard))

* Run **make** on terminal to compile;
* Run **make clean** to clean;
* Run **make valgrind** to execute valgrind to test for memory leakage;
