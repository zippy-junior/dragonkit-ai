#ifndef layer_dense_cpp
#define layer_dense_cpp

#include "layerDense.hpp"
#include "tensor.hpp"
#include "generator.hpp"
#include "iostream"

using namespace std;

template <typename T, unsigned Inputs, unsigned Neurons>
layerDense<T, Inputs, Neurons>::layerDense() : weights(&randomFloatFill),
                                               bias(0)
{
  this->weights = this->weights * 0.01;
}

template <typename T, unsigned Inputs, unsigned Neurons>
layerDense<T, Inputs, Neurons>::~layerDense()
{
}

template <typename T, unsigned Inputs, unsigned Neurons>
void layerDense<T, Inputs, Neurons>::forward(const tensor2<float, 3, 3> &inputs)
{
}

template <typename T, unsigned Inputs, unsigned Neurons>
void layerDense<T, Inputs, Neurons>::printWeights()
{
  this->weights.printTensor();
}

template <typename T, unsigned Inputs, unsigned Neurons>
void layerDense<T, Inputs, Neurons>::printBias()
{
  this->bias.printTensor();
}

#endif