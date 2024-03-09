#ifndef loss_mean_cpp
#define loss_mean_cpp

#include "../tensor.hpp"

template <typename T, unsigned X>
double lossMean(const tensor1<T, X> &input)
{
  double sum = 0;
  for (size_t row = 0; row < X; row++)
  {
    sum += input(row);
  }
  return sum / input.getColumns();
}

#endif