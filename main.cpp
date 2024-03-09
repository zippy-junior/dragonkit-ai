#include "tensor.hpp"
#include "layerDense.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include "generator.hpp"
#include "test_data.cpp"
#include "activators/activators.hpp"
#include "loss/loss.hpp"

using namespace std;

extern tensor2<double, 300, 2> TEST_DATA;
extern tensor2<int, 300, 3> TEST_TARGET;

int main()
{
  layerDense<double, 2, 3, 300> dense1;
  layerDense<double, 3, 3, 300> dense2;
  tensor2<double, 300, 3> res1 = dense1.forward(TEST_DATA);
  ReLU<double, 300, 3> activator1;
  tensor2<double, 300, 3> processed1 = activator1.forward(res1);
  tensor2<double, 300, 3> res2 = dense2.forward(processed1);
  SoftMax<double, 300, 3> activator2;
  tensor2<double, 300, 3> processed2 = activator2.forward(res2);
  tensor1<double, 300> loss = CrossEntropyLoss<double, 300, 3>(processed2, TEST_TARGET);
  loss.printTensor();
  return 0;
}