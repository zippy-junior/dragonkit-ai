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
  int ROWS;
  int COLS;
  std::array<std::array<T, Y>, X> mat;

public:
  // Constructor 1
  // tensor2(const T &init);

  // Constructor 2
  tensor2(T (*func)());

  // Constructor 3
  tensor2(const std::array<std::array<T, Y>, X> &arr);

  // Copy constructor
  tensor2(const tensor2<T, X, Y> &A);

  // Destructor
  virtual ~tensor2();

  // PUBLIC METHODS

  int getRows() const;    // Get tensor2 Size.
  int getColumns() const; // Get tensor2 Size.
  void printTensor();     // Print complete tensor2.
  // void printVector(vector<T> vec);               // Print an std::vector.
  // T &getElement(int row, int col);               // Get individual element.
  void updateElement(int row, int col, T value); // Update individual
  // element.

  // OPERATORS

  T &operator()(const int &row, const int &col);
  const T &operator()(const unsigned &row, const unsigned &col) const;
  tensor2<T, X, Y> &operator=(const tensor2<T, X, Y> &A);
  tensor2<T, X, Y> operator+(const tensor2<T, X, Y> &A);
  // tensor2<T> operator-(const tensor2<T> &A);

  // Dot product
  tensor2<T, (X > Y ? Y : X), (X > Y ? Y : X)> product(const tensor2<T, Y, X> &A);

  // Hadamard product
  // vector<T> vectorHadamardProduct(vector<T> a, vector<T> b);
  // tensor2<T> tensor2HadamardProduct(tensor2<T> A, tensor2<T> B);

  // Numerical
  // void getCoFactors(vector<vector<T>> array, vector<vector<T>> &temp, int
  // size, int r, int c); // Calculate tensor2 cofactors for computing the
  // determinant. T iterateDet(vector<vector<T>> array, int size); T
  // getDeterminant(int size);            // Determinant of a square tensor2.
  // tensor2<T> scalarTimestensor2(T scalar); // Scalar-tensor2 multiplication.
  // tensor2<T> scalarPlustensor2(T scalar);  // Scalar-tensor2 sum.
  // tensor2<T> scalarMinustensor2(T scalar); // Scalar-tensor2 substraction.
  // vector<T> diagonalVector();            // Vector with the diagonal elements
  // of the tensor2.

  // Transformations
  // tensor2<T> identity();  // Identity tensor2.
  tensor2<T, Y, X> transpose(); // Transpose of the original tensor2.
  // tensor2<T> adjoint();   // Adjoint of a square tensor2.
  // tensor2<T> inverse();   // Inverse of a square tensor2.

  // Rotation and Transform matrices
  // tensor2<T> getRotationtensor2(vector<T> rpy, bool radians);
  // tensor2<T> getTransformtensor2(vector<T> xyz, vector<T> rpy, bool radians);
  // vector<T> getTranslationVector(tensor2<T> transform_tensor2);
  // vector<T> getRpyVector(tensor2<T> transform_tensor2);
};

template <typename T, unsigned X>
class tensor1
{
private:
  int COLS;
  std::array<T, X> mat;

public:
  // Constructor by fill
  tensor1(const T &fill);
  // Constructor by array
  tensor1(const std::array<T, X> &arr);
  // Copy constructor
  tensor1(const tensor1<T, X> &A);

  // Destructor
  virtual ~tensor1();

  // PUBLIC METHODS

  int getColumns() const; // Get Matrix Size.
  void printTensor();     // Print complete matrix.
  T &getElement(int col); // Get individual element.
  // void updateElement(int row, int col, T value); // Update individual
  // element.

  // OPERATORS

  T &operator()(const int &col);
  const T &operator()(const unsigned &col) const;
  tensor1<T, X> &operator=(const tensor1<T, X> &A);
  tensor1<T, X> operator+(const tensor1<T, X> &A);
  // tensor1<T> operator-(const tensor1<T> &A);
  tensor1<T, X> operator*(const tensor1<T, X> &A);

  // ALGEBRA

  // Multiplications
  // vector<T> matrixByColumnVector(vector<T> vec);                // Matrix by
  // Column Vector multiplication (result = vector). vector<T>
  // rowVectorByMatrix(vector<T> vec);                   // Row Vector by Matrix
  // Multiplication (result = vector). tensor1<T>
  // columnVectorByRowVector(vector<T> a, vector<T> b); // Column Vector by Row
  // Vector multiplication (result = Matrix).

  // Hadamard product
  // vector<T> vectorHadamardProduct(vector<T> a, vector<T> b);
  // tensor1<T> matrixHadamardProduct(tensor1<T> A, tensor1<T> B);

  // Numerical
  // void getCoFactors(vector<vector<T>> array, vector<vector<T>> &temp, int
  // size, int r, int c); // Calculate matrix cofactors for computing the
  // determinant. T iterateDet(vector<vector<T>> array, int size); T
  // getDeterminant(int size);             // Determinant of a square matrix.
  // tensor1<T> scalarTimesMatrix(T scalar); // Scalar-matrix multiplication.
  // tensor1<T> scalarPlusMatrix(T scalar);  // Scalar-matrix sum.
  // tensor1<T> scalarMinusMatrix(T scalar); // Scalar-matrix substraction.
  // vector<T> diagonalVector();             // Vector with the diagonal
  // elements of the matrix.

  // Transformations
  // tensor1<T> identity();  // Identity matrix.
  // tensor1<T> transpose(); // Transpose of the original matrix.
  // tensor1<T> adjoint();   // Adjoint of a square matrix.
  // tensor1<T> inverse();   // Inverse of a square matrix.

  // Rotation and Transform matrices
  // tensor1<T> getRotationMatrix(vector<T> rpy, bool radians);
  // tensor1<T> getTransformMatrix(vector<T> xyz, vector<T> rpy, bool radians);
  // vector<T> getTranslationVector(tensor1<T> transform_matrix);
  // vector<T> getRpyVector(tensor1<T> transform_matrix);
};

template <typename T, unsigned X, unsigned Y, unsigned Y2>
tensor2<T, X, (Y2 > Y ? Y : Y2)> operator*(const tensor2<T, X, Y> &A, const tensor2<T, Y, Y2> &B);

template <typename T, unsigned X, unsigned Y>
tensor1<T, X> operator*(const tensor1<T, Y> &A, const tensor2<T, X, Y> &B);

template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y> operator*(const tensor2<T, X, Y> &A, const double &D);

template <typename T, unsigned X, unsigned Y>
tensor2<T, X, Y> operator+(const tensor2<T, X, Y> &A, const tensor1<T, Y> &B);

#include "tensor2.cpp"
#include "tensor1.cpp"

#endif // tensor2_H