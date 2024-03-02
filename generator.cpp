#ifndef generator_cpp
#define generator_cpp

#include <random>

using namespace std;
float internalRandomFloat()
{
  return (float)(arc4random()) / (float)(RAND_MAX);
}

int randomInt(int a, int b)
{
  if (a > b)
    return randomInt(b, a);
  if (a == b)
    return a;
  return a + (arc4random() % (b - a));
}

float randomFloatFill()
{
  return (float)randomInt(-1, 1) + internalRandomFloat();
}

float zeroFill()
{
  return 0.0;
}

#endif