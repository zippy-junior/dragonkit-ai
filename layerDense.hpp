#ifndef layer_dense
#define layer_dense
#include "tensor.hpp"

template <typename T, unsigned Inputs, unsigned Neurons>
class layerDense
{
private:
  tensor2<T, Inputs, Neurons> weights;
  tensor1<T, Neurons> bias;

public:
  layerDense();
  ~layerDense();
  void forward(const tensor2<float, 3, 3> &inputs);
  void printWeights();
  void printBias();
};

#include "layerDense.cpp"

#endif