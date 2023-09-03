#!/bin/sh
gcc -c *
ar -rc libft.a *.o

ranlib

rm -rf *.o
