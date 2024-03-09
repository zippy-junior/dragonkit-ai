#ifndef relu_cpp
#define relu_cpp

#include "../tensor.hpp"
#include "../generator.hpp"
#include "activators.hpp"

template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y> ReLU<T, X, Y>::forward(const tensor2<T, X, Y> &input)
{
  tensor2<T, X, Y> result(zeroFill<T>);
  for (size_t row = 0; row < X; row++)
  {
    for (size_t col = 0; col < Y; col++)
    {
      result(row, col) = input(row, col) < 0 ? 0 : input(row, col);
    }
  }
  return result;
}

template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y> ReLU<T, X, Y>::backward(const tensor2<T, X, Y> &input)
{
  tensor2<T, X, Y> result(zeroFill<T>);
  // for (size_t row = 0; row < X; row++)
  // {
  //   for (size_t col = 0; col < Y; col++)
  //   {
  //     result(row, col) = input(row, col) < 0 ? 0 : input(row, col);
  //   }
  // }
  return result;
}

#endif