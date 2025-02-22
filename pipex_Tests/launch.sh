#!/bin/bash
clear
gcc -g Unity-master/src/*.c */*.c ../pipex_project/*.c ../pipex_project/*/*.c main.c  && valgrind --track-origins=yes -s --leak-check=full ./a.out
gcc -fsanitize=address  Unity-master/src/*.c */*.c ../pipex_project/*.c ../pipex_project/*/*.c main.c  && ./a.out