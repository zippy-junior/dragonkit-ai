#include "tensor.hpp"
#include "layerDense.hpp"
#include <iostream>
#include <vector>
#include "generator.hpp"
#include "test_data.cpp"
#include "activators/activators.hpp"

using namespace std;

extern tensor2<double, 100, 2> TEST_DATA;

int main()
{
  layerDense<double, 2, 4, 100> test;
  tensor2<double, 100, 4> res = test.forward(TEST_DATA);
  // res.printTensor();
  tensor2<double, 100, 4> processed = ReLU<double, 100, 4>(res);
  processed.printTensor();
  return 0;
}