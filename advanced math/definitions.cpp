#include "stdafx.h"

#include "definitions.h"

namespace adv_math {

long long factorial( int I ) {
  if (I == 0)
    return 1;

  return factorial(I - 1) * I;
}

point point::operator+( const point &R ) const {
  return point({ X + R.X, Y + R.Y });
}

point & point::operator+=( const point &R ) {
  X += R.X;
  Y += R.Y;
  return *this;
}

point point::operator-( const point &R ) const {
  return point({ X - R.X, Y - R.Y });
}

point & point::operator-=( const point &R ) {
  X -= R.X;
  Y -= R.Y;
  return *this;
}

point & point::operator*( double Mul ) {
  X *= Mul;
  Y *= Mul;
  return *this;
}

point & operator*( double Mul, point &P ) {
  return P * Mul;
}

grid::grid( const std::vector<double> &Xs, const std::vector<double> &Ys ) {
  int Size = min(Xs.size(), Ys.size());
  resize(Size);
  for (int i = 0; i < Size; i++)
    at(i) = { Xs[i], Ys[i] };
}

std::vector<double> grid::X( void ) const {
  std::vector<double> Res;

  for (const auto &it : *this)
    Res.push_back(it.X);
  return Res;
}

std::vector<double> grid::Y( void ) const {
  std::vector<double> Res;

  for (const auto &it : *this)
    Res.push_back(it.Y);
  return Res;
}

grid_derivative::grid_derivative( const grid &XY ) {
  resize(2);
  at(0) = XY.X();
  at(1) = XY.Y();
}

grid_derivative::grid_derivative( const std::initializer_list<std::vector<double>> &Rows ) {
  reserve(Rows.size());
  for (const auto &it : Rows)
    push_back(it);
}

grid_derivative::operator grid() const {
  return grid(at(0), at(1));
}

std::vector<double> & grid_derivative::operator[]( int Derivative ) {
  return at(Derivative + 1);
}

const std::vector<double> & grid_derivative::operator[]( int Derivative ) const {
  return at(Derivative + 1);
}

} // End of 'adv_math' namespace
