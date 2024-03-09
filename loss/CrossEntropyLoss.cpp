#ifndef cross_entropy_loss_cpp
#define cross_entropy_loss_cpp

#include <cmath>
#include "../tensor.hpp"

double SMALLN = 1e-8;

template <typename T, unsigned X, unsigned Y>
tensor1<T, X> CrossEntropyLoss(const tensor2<T, X, Y> &input, const tensor2<int, X, Y> &targets)
{
  tensor1<T, X> result(zeroFill<T>);
  // TODO make type safe alternative for target values
  // TODO upgrade performance with accepting targets as tensor1 and indexing input value right away
  for (size_t row = 0; row < X; row++)
  {
    for (size_t col = 0; col < Y; col++)
    {
      if (targets(row, col))
      {
        result(row) = log(input(row, col));
      }
    }
  }
  return result;
}

#endif