#ifndef tensor1_cpp
#define tensor1_cpp

#include "tensor.hpp"

using namespace std;

// CONSTRUCTOR BY (FILL FUNCTION)
template <typename T, unsigned X>
tensor1<T, X>::tensor1(T (*func)())
{
  ROWS = X;
  for (size_t row = 0; row < ROWS; row++)
  {
    mat[row] = func();
  }
}

// CONSTRUCTOR BY (ARRAY<T>)
template <typename T, unsigned X>
tensor1<T, X>::tensor1(const array<T, X> &arr)
{
  ROWS = arr.size();
  mat = arr;
}

// COPY CONSTRUCTOR
template <typename T, unsigned X>
tensor1<T, X>::tensor1(const tensor1<T, X> &A)
{
  mat = A.mat;
  ROWS = A.ROWS;
}

// DESTRUCTOR
template <typename T, unsigned X>
tensor1<T, X>::~tensor1()
// tensor1::~tensor1()
{
  // cout << "tensor1 succesfully destroyed." << endl;
}

//----------------------------------------------------------------------------------------------------

// PUBLIC METHODS

// Get number of columns
template <typename T, unsigned X>
int tensor1<T, X>::getRows() const
// int tensor1::getColumns()
{
  return this->ROWS;
}

// Print whole tensor1
template <typename T, unsigned X>
void tensor1<T, X>::printTensor()
// void tensor1::printTensor()
{
  int limit = X - 1;
  cout << "tensor1[" << X << "]:" << endl
       << endl;
  for (int row = 0; row < X; row++)
  {
    if (row == limit)
    {
      cout << this->mat[row];
    }
    else
    {
      cout << this->mat[row] << ",";
    }
  }
  cout << endl;
  cout << endl;
}

// Print vector
// template <typename T>
// void tensor1<T>::printVector(vector<T> vec)
// {
//   cout << "[" << vec[0];
//   for (int i = 1; i < vec.size(); i++)
//   {
//     cout << ", " << vec[i];
//   }
//   cout << "]" << endl;
// }

// Get individual element
template <typename T, unsigned X>
T &tensor1<T, X>::getElement(unsigned row)
{
  return this->mat[row];
}

// Update individual value
// template <typename T>
// void tensor1<T>::updateElement(int row, int col, T value)
// {
//   mat[row][col] = value;
// }

//----------------------------------------------------------------------------------------------------

// OPERATORS

// Access individual elements
template <typename T, unsigned X>
T &tensor1<T, X>::operator()(const unsigned &col)
{
  return this->mat[col];
}

// Access individual elements const version
template <typename T, unsigned X>
const T &tensor1<T, X>::operator()(const unsigned &col) const
{
  return this->mat[col];
}

// Assignment Operator
template <typename T, unsigned X>
tensor1<T, X> &tensor1<T, X>::operator=(const tensor1<T, X> &A)
{
  if (&A == this)
    return *this;

  for (int row = 0; row < X; row++)
  {
    mat[row] = A(row);
  }
  ROWS = X;
  return *this;
}

// Sum of two matrices
template <typename T, unsigned X>
tensor1<T, X> tensor1<T, X>::operator+(const tensor1<T, X> &A)
{
  tensor1<T, X> result(0);
  for (int row = 0; row < ROWS; row++)
  {
    // T val = A.getElement(i, j);
    T newVal = this->mat[row] + A(row);
    result(row) = newVal;
  }
  return result;
}

// Subtraction of this tensor1 and another
// template <typename T>
// tensor1<T> tensor1<T>::operator-(const tensor1<T> &A)
// {
//   tensor1 result(ROWS, COLS, 0);

//   for (int i = 0; i < ROWS; i++)
//   {
//     for (int j = 0; j < COLS; j++)
//     {
//       // T val = A.getElement(i, j);
//       T newVal = this->mat[i][j] - A(i, j);
//       result.updateElement(i, j, newVal);
//     }
//   }
//   return result;
// }

template <typename T, unsigned X, unsigned Y>
tensor1<T, X> operator*(const tensor1<T, Y> &A, const tensor2<T, X, Y> &B)
{
  tensor1<T, X> result(0);

  for (int row = 0; row < B.getRows(); row++)
  {
    for (int col = 0; col < B.getColumns(); col++)
    {
      result(row) += A(col) * B(row, col);
    }
  }
  return result;
}

//----------------------------------------------------------------------------------------------------

#endif // tensor1_CPP