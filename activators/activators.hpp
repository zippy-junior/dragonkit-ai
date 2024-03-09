#ifndef activators_hpp
#define activators_hpp
#include "../tensor.hpp"

template <typename T, unsigned X, unsigned Y>
class Activator
{
public:
  virtual tensor2<T, X, Y> forward(const tensor2<T, X, Y> &input) = 0;
  virtual tensor2<T, X, Y> backward(const tensor2<T, X, Y> &input) = 0;
};

template <typename T, unsigned X, unsigned Y>
class ReLU : public Activator<T, X, Y>
{
public:
  tensor2<T, X, Y> forward(const tensor2<T, X, Y> &input) override;
  tensor2<T, X, Y> backward(const tensor2<T, X, Y> &input) override;
};

template <typename T, unsigned X, unsigned Y>
class SoftMax : public Activator<T, X, Y>
{
public:
  tensor2<T, X, Y> forward(const tensor2<T, X, Y> &input) override;
  tensor2<T, X, Y> backward(const tensor2<T, X, Y> &input) override;
};

#include "ReLU.cpp"
#include "SoftMax.cpp"

#endif