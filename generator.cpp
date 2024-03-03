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

template <typename T>
T randomFill()
{
  return (T)randomInt(-1, 1) + (T)internalRandomFloat();
}

template <typename T>
T zeroFill()
{
  return (T)0;
}

#endif