#ifndef soft_max_cpp
#define soft_max_cpp

#include "../tensor.hpp"
#include "../generator.hpp"
#include <cmath>
#include <iostream>

double EXPONENT = 2.71828182846;

template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y> SoftMax<T, X, Y>::forward(const tensor2<T, X, Y> &input)
{
  tensor2<T, X, Y> result(zeroFill<T>);
  for (size_t row = 0; row < X; row++)
  {
    T max = input(row, 0);
    for (size_t col = 0; col < Y; col++)
    {
      max = input(row, col) < max ? max : input(row, col);
    }
    T sum = 0;
    for (size_t col = 0; col < Y; col++)
    {
      result(row, col) = pow(EXPONENT, input(row, col) - max);
      sum += result(row, col);
    }
    for (size_t col = 0; col < Y; col++)
    {
      result(row, col) /= sum;
    }
  }
  return result;
}

template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y> SoftMax<T, X, Y>::backward(const tensor2<T, X, Y> &input)
{
  tensor2<T, X, Y> result(zeroFill<T>);
  return result;
}

#endif