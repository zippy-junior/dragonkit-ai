#ifndef loss_hpp
#define loss_hpp

#include "../tensor.hpp"

// class CrossEntropyLoss
// {

// };

template <typename T, unsigned X, unsigned Y>
tensor1<T, X> CrossEntropyLoss(const tensor2<T, X, Y> &input, const tensor2<int, X, Y> &targets);

template <typename T, unsigned X>
double lossMean(const tensor1<T, X> &input);

#include "CrossEntropyLoss.cpp"
#include "lossMean.cpp"

#endif