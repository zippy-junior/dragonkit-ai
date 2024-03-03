#include "tensor.hpp"
#include "layerDense.hpp"
#include <iostream>
#include <vector>
#include "generator.hpp"
#include "test_data.cpp"

using namespace std;

extern tensor2<double, 100, 2> TEST_DATA;

int main()
{
  layerDense<double, 2, 4, 100> test;
  tensor2<double, 100, 4> res = test.forward(TEST_DATA);
  res.printTensor();
  return 0;
}