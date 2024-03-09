#ifndef tensor_hpp
#define tensor_hpp

#include <array>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#define PI 3.14159265359

using namespace std;

template <typename T, unsigned X, unsigned Y>
class tensor2
{
private:
  unsigned ROWS;
  unsigned COLS;
  std::array<std::array<T, Y>, X> mat;

public:
  // Constructor 1
  // tensor2(const T &init);

  // Constructor 2
  tensor2(T (&func)());

  // Constructor 3
  tensor2(const std::array<std::array<T, Y>, X> &arr);

  // Copy constructor
  tensor2(const tensor2<T, X, Y> &A);

  // Destructor
  virtual ~tensor2();

  // PUBLIC METHODS

  unsigned getRows() const;    // Get tensor2 Size.
  unsigned getColumns() const; // Get tensor2 Size.
  void printTensor();          // Print complete tensor2.
  // T &getElement(int row, int col);               // Get individual element.
  void updateElement(int row, int col, T value); // Update individual
  // element.

  // OPERATORS

  T &operator()(const size_t &row, const size_t &col);
  const T &operator()(const size_t &row, const size_t &col) const;
  tensor2<T, X, Y> &operator=(const tensor2<T, X, Y> &A);
  tensor2<T, X, Y> operator+(const tensor2<T, X, Y> &A);
  // tensor2<T> operator-(const tensor2<T> &A);

  // Transformations
  tensor2<T, Y, X> transpose(); // Transpose of the original tensor2.
};

template <typename T, unsigned X>
class tensor1
{
private:
  unsigned ROWS;
  std::array<T, X> mat;

public:
  // Constructor by fill function
  tensor1(T (*func)());
  // Constructor by array
  tensor1(const std::array<T, X> &arr);
  // Copy constructor
  tensor1(const tensor1<T, X> &A);

  // Destructor
  virtual ~tensor1();

  // PUBLIC METHODS

  int getRows() const;         // Get Tensor 1 Size.
  void printTensor();          // Print complete matrix.
  T &getElement(unsigned row); // Get individual element.
  // void updateElement(int row, int col, T value); // Update individual
  // element.

  // OPERATORS

  T &operator()(const unsigned &col);
  const T &operator()(const unsigned &col) const;
  tensor1<T, X> &operator=(const tensor1<T, X> &A);
  tensor1<T, X> operator+(const tensor1<T, X> &A);
  // tensor1<T> operator-(const tensor1<T> &A);
};

template <typename T, unsigned X, unsigned Y, unsigned Y2>
tensor2<T, X, Y2> operator*(const tensor2<T, X, Y> &A, const tensor2<T, Y, Y2> &B);

template <typename T, unsigned X, unsigned Y>
tensor1<T, X> operator*(const tensor1<T, Y> &A, const tensor2<T, X, Y> &B);

template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y> operator*(const tensor2<T, X, Y> &A, const double &D);

template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y> operator+(const tensor2<T, X, Y> &A, const tensor1<T, Y> &B);

#include "tensor2.cpp"
#include "tensor1.cpp"

#endif // tensor2_H