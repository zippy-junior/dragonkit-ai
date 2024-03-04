#ifndef layer_dense_cpp
#define layer_dense_cpp

#include "layerDense.hpp"
#include "tensor.hpp"
#include "generator.hpp"
#include "iostream"

using namespace std;

template <typename T, unsigned Inputs, unsigned Neurons, unsigned BatchSize>
layerDense<T, Inputs, Neurons, BatchSize>::layerDense() : weights(randomFill<T>),
                                                          bias(zeroFill<T>)
{
  this->weights = this->weights * 0.01;
}

template <typename T, unsigned Inputs, unsigned Neurons, unsigned BatchSize>
layerDense<T, Inputs, Neurons, BatchSize>::~layerDense()
{
}

template <typename T, unsigned Inputs, unsigned Neurons, unsigned BatchSize>
tensor2<T, BatchSize, Neurons> layerDense<T, Inputs, Neurons, BatchSize>::forward(tensor2<T, BatchSize, Inputs> &inputs)
{
  tensor2<T, BatchSize, Neurons> res = inputs * this->weights + this->bias;
  return res;
}

template <typename T, unsigned Inputs, unsigned Neurons, unsigned BatchSize>
void layerDense<T, Inputs, Neurons, BatchSize>::printWeights()
{
  this->weights.printTensor();
}

template <typename T, unsigned Inputs, unsigned Neurons, unsigned BatchSize>
void layerDense<T, Inputs, Neurons, BatchSize>::printBias()
{
  this->bias.printTensor();
}

#endif