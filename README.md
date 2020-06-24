# matrixClass

This class holds a c++ standard library vector in A^(n*m) space, where the set A can be: Z the set of integers, N the set of natural number, R the set of real Numbers. With this class you can perform the usual overloaded binary operations necessary for matrix arithmetic (e.g. +,-,*). Definite shortcomings of this class is scalability. Any matrix addition, subtraction and finding the max number is O(n^2). My implementation of Matrix multiplication is O(n^3). There are much more efficient algorithms for these methods.
