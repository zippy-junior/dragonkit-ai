#ifndef tensor1_cpp
#define tensor1_cpp

#include "tensor.hpp"

using namespace std;

// CONSTRUCTOR BY (FILL)
template <typename T, unsigned X>
tensor1<T, X>::tensor1(const T &fill)
{
  COLS = X;
  mat.fill(fill);
}

// CONSTRUCTOR BY (ARRAY<T>)
template <typename T, unsigned X>
tensor1<T, X>::tensor1(const array<T, X> &arr)
{
  COLS = arr.size();
  mat = arr;
}

// COPY CONSTRUCTOR
template <typename T, unsigned X>
tensor1<T, X>::tensor1(const tensor1<T, X> &A)
{
  mat = A.mat;
  COLS = A.COLS;
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
int tensor1<T, X>::getColumns() const
// int tensor1::getColumns()
{
  return this->COLS;
}

// Print whole tensor1
template <typename T, unsigned X>
void tensor1<T, X>::printTensor()
// void tensor1::printTensor()
{
  int c = getColumns();
  int limit = c - 1;
  cout << "tensor1[" << c << "]:" << endl
       << endl;
  for (int i = 0; i < c; i++)
  {
    if (i == limit)
    {
      cout << this->mat[i];
    }
    else
    {
      cout << this->mat[i] << ",";
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
T &tensor1<T, X>::getElement(int col)
{
  return this->mat[col];
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
T &tensor1<T, X>::operator()(const int &col)
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

  int new_cols = A.getColumns();

  for (int col = 0; col < new_cols; col++)
  {
    mat[col] = A(col);
  }
  COLS = new_cols;
  return *this;
}

// Sum of two matrices
template <typename T, unsigned X>
tensor1<T, X> tensor1<T, X>::operator+(const tensor1<T, X> &A)
{
  tensor1<T, X> result(0);
  for (int col = 0; col < COLS; col++)
  {
    // T val = A.getElement(i, j);
    T newVal = this->mat[col] + A(col);
    result(col) = newVal;
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

// Multiplication of this tensor1 and another
template <typename T, unsigned X>
tensor1<T, X> tensor1<T, X>::operator*(const tensor1<T, X> &A)
{
  tensor1<T, X> result(0);

  for (int col = 0; col < COLS; col++)
  {
    for (int col2 = 0; col < COLS; col++)
    {
      result(col) += this->mat[col] * A(col2);
    }
  }
  return result;
}

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