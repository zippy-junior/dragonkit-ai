#ifndef tensor2_cpp
#define tensor2_cpp

#include "tensor.hpp"
#include "generator.hpp"
#include <array>

using namespace std;

// CONSTRUCTOR BY (FILL)
// template <typename T, unsigned X, unsigned Y>
// tensor2<T, X, Y>::tensor2(const T &fill)
// // tensor2::tensor2(const float init)
// {
//   ROWS = X;
//   COLS = Y;
//   for (size_t i = 0; i < mat.size(); i++)
//   {
//     mat[i].fill(fill);
//   }
// }

// CONSTRUCTOR BY (FILL FUNCTION)
template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y>::tensor2(T (*func)())
// tensor2::tensor2(const float init)
{
  ROWS = X;
  COLS = Y;
  for (size_t row = 0; row < ROWS; row++)
  {
    for (size_t col = 0; col < COLS; col++)
    {
      mat[row][col] = func();
    }
  }
}

// CONSTRUCTOR BY (ARRAY<ARRAY<T>>)
template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y>::tensor2(const std::array<std::array<T, Y>, X> &arr)
// tensor2::tensor2(&vector<vector<T>> &arr)
{
  ROWS = X;
  COLS = Y;
  mat = arr;
}

// COPY CONSTRUCTOR
template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y>::tensor2(const tensor2<T, X, Y> &A)
{
  mat = A.mat;
  ROWS = A.getRows();
  COLS = A.getColumns();
}

// DESTRUCTOR
template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y>::~tensor2()
// tensor2::~tensor2()
{
  // cout << "tensor2 succesfully destroyed." << endl;
}

//----------------------------------------------------------------------------------------------------

// PUBLIC METHODS

// Get number of rows
template <typename T, unsigned X, unsigned Y>
int tensor2<T, X, Y>::getRows() const
// int tensor2::getRows()
{
  return this->ROWS;
}

// Get number of columns
template <typename T, unsigned X, unsigned Y>
int tensor2<T, X, Y>::getColumns() const
// int tensor2::getColumns()
{
  return this->COLS;
}

// Print whole tensor2
template <typename T, unsigned X, unsigned Y>
void tensor2<T, X, Y>::printTensor()
// void tensor2::printtensor2()
{
  int r = getRows();
  int c = getColumns();
  int limit = c - 1;
  cout << "tensor2[" << r << "][" << c << "]:" << endl
       << endl;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (j == limit)
      {
        cout << this->mat[i][j];
      }
      else
      {
        cout << this->mat[i][j] << ",";
      }
    }
    cout << endl;
  }
  cout << endl;
}

// Update individual value
template <typename T, unsigned X, unsigned Y>
void tensor2<T, X, Y>::updateElement(int row, int col, T value)
{
  mat[row][col] = value;
}

//----------------------------------------------------------------------------------------------------

// OPERATORS

// Access individual elements
template <typename T, unsigned X, unsigned Y>
T &tensor2<T, X, Y>::operator()(const int &row, const int &col)
{
  return this->mat[row][col];
}

// Access individual elements const version
template <typename T, unsigned X, unsigned Y>
const T &tensor2<T, X, Y>::operator()(const unsigned &row, const unsigned &col)
    const
{
  return this->mat[row][col];
}

// Assignment Operator
template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y> &tensor2<T, X, Y>::operator=(const tensor2<T, X, Y> &A)
{
  if (&A == this)
    return *this;

  int new_rows = A.getRows();
  int new_cols = A.getColumns();

  for (int i = 0; i < new_rows; i++)
  {
    for (int j = 0; j < new_cols; j++)
    {
      mat[i][j] = A(i, j);
    }
  }

  ROWS = new_rows;
  COLS = new_cols;

  return *this;
}

// Sum of two matrices
template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y> tensor2<T, X, Y>::operator+(const tensor2<T, X, Y> &A)
{
  tensor2<T, X, Y> result(0);

  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      // T val = A.getElement(i, j);
      T newVal = this->mat[i][j] + A(i, j);
      result.updateElement(i, j, newVal);
    }
  }
  return result;
}

template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y> operator+(const tensor2<T, X, Y> &A, const tensor1<T, Y> &B)
{
  tensor2<T, X, Y> result(0);
  for (int row = 0; row < Y; row++)
  {
    for (int col = 0; col < X; col++)
    {
      result(row, col) = A(row, col) + B(col);
    }
  }
  return result;
}

// Multiplication of this tensor2 and another
template <typename T, unsigned X, unsigned Y, unsigned Y2>
tensor2<T, X, Y2> operator*(const tensor2<T, X, Y> &A, const tensor2<T, Y, Y2> &B)
{
  tensor2<T, X, Y2> result(&zeroFill<T>);

  for (size_t i = 0; i < X; i++)
  {
    for (size_t j = 0; j < Y2; j++)
    {
      for (size_t k = 0; k < Y; k++)
      {
        result(i, j) += A(i, k) * B(k, j);
      }
    }
  }
  return result;
}

template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y> operator*(const tensor2<T, X, Y> &A, const double &D)
{
  tensor2<T, X, Y> result(&zeroFill<T>);
  for (size_t row = 0; row < X; row++)
  {
    for (size_t col = 0; col < Y; col++)
    {
      result(row, col) = A(row, col) * D;
    }
  }
  return result;
}

// // Transpose
template <typename T, unsigned X, unsigned Y>
tensor2<T, Y, X> tensor2<T, X, Y>::transpose()
{
  tensor2<T, Y, X> t(&zeroFill<T>);
  for (int i = 0; i < COLS; i++)
  {
    for (int j = 0; j < ROWS; j++)
    {
      t.updateElement(i, j, this->mat[j][i]);
    }
  }
  return t;
}

// //----------------------------------------------------------------------------------------------------

#endif // tensor2_CPP