#include <iostream>
#include <cmath>
#include "Vector.h"

Vector::Vector(int sz)
{
  size = 0;
  data = new double [size]; // PROVIDE CODE
}

Vector::~Vector()
{
  if (data != 0)
    delete [] data; // PROVIDE CODE
}

// some methods
int 
Vector::Size(void) const
{
  return size;
}

void 
Vector::zero(void)
{
  for (int i=0; i<size; i++)
    data[i] = 0;
}

double 
Vector::norm(void) const
{
  return sqrt(this->dot(*this));// PROVIDE CODE
}

double 
Vector::dot(const Vector &other) const
{
  double result = 0;
  
  if (other.size != size) {
    std::cerr << "Vector::dot ERROR vectors not of same size, returning 0\n";
    return result;
  }
  
  // PROVIDE CODE
  for (int i = 0;i<size;i++){
    result += data[i] * other.data[i];
  }

  
  return result;
}

void 
Vector::print(void)
{
  for (int i=0; i<size; i++)
    std::cerr << " " << data[i];
  std::cerr << "\n";
}

// overload some operators to look Matlabish
Vector 
Vector::operator+(const Vector &other) const
{
  Vector result(size);

  if (other.size != size) {
    std::cerr << "Vector::operator ERROR vectors not of same size, returning empty vector\n";
    return result;
  }

  // PROVIDE CODE
  for (int i = 0;i<size;i++){
    result.data[i] = data[i] + other.data[i]; 
  }
  return result;
}

void 
Vector::operator=(const Vector &other)
{
  // PROVIDE CODE
  for (int i = 0;i<size;i++){
    data[i] = other.data[i]; 
  }
}

void 
Vector::operator+=(double val)
{
  // PROVIDE CODE
  for (int i = 0;i<size;i++){
    data[i] += val; 
  }
}

void 
Vector::operator+=(const Vector &other)
{
  // PROVIDE CODE
  for (int i = 0;i<size;i++){
    data[i] += other.data[i]; 
  }
}

double 
Vector::operator()(int x) const
{
  // PROVIDE CODE
  return data[x];
}

double &
Vector::operator()(int x)
{
  if (x < 0 || x >= size) {
    static double errorResult = 0;
    std::cerr << "Vector::operator() " << x << " outside range 0 through " << size-1 << "\n";
    return errorResult;
  }
  // PROVIDE CODE
  return data[x];
}

