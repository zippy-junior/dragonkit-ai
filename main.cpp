#include "tensor.hpp"
#include "layerDense.hpp"
#include <iostream>
#include <vector>
#include "generator.hpp"

using namespace std;

int main()
{
  tensor2<double, 3, 4> inputs({{{1.0, 2.0, 3.0, 2.5},
                                 {2.0, 5.0, -1.0, 2.0},
                                 {-1.5, 2.7, 3.3, -0.8}}});
  tensor2<float, 3, 4> test(&randomFloatFill);
  tensor2<float, 3, 4> res = test * 0.01;
  test.printTensor();
  res.printTensor();
  // tensor2<double, 3, 4> weights1({{{0.2, 0.8, -0.5, 1},
  //                                  {0.5, -0.91, 0.26, -0.5},
  //                                  {-0.26, -0.27, 0.17, 0.87}}});
  // tensor2<double, 3, 3> weights2({{{0.1, -0.14, 0.5},
  //                                  {-0.5, 0.12, -0.33},
  //                                  {-0.44, 0.73, -0.13}}});
  // tensor2<double, 4, 3> weights1T = weights1.transpose();
  // tensor2<double, 3, 3> weights2T = weights2.transpose();
  // tensor1<double, 3> bias1({2.0, 3.0, 0.5});
  // tensor1<double, 3> bias2({-1.0, 2.0, -0.5});
  // tensor2<double, 3, 3> layer1output = inputs.product(weights1T) + bias1;
  // tensor2<double, 3, 3> layer2output = layer1output.product(weights2T) + bias2;
  // layer2output.printTensor();

  // layerDense<float, 5, 5> test;
  // test.printWeights();
  // return 0;
}