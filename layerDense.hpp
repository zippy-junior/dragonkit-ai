#ifndef layer_dense
#define layer_dense
#include "tensor.hpp"

template <typename T, unsigned Inputs, unsigned Neurons, unsigned BatchSize>
class layerDense
{
private:
  tensor2<T, Inputs, Neurons> weights;
  tensor1<T, Neurons> bias;

public:
  layerDense();
  ~layerDense();
  tensor2<T, BatchSize, Neurons> forward(tensor2<T, BatchSize, Inputs> &inputs);
  void printWeights();
  void printBias();
};

#include "layerDense.cpp"

#endif