#pragma once

#include "stdafx.h"

namespace adv_math {

static const double Pi = 3.1415926535897932384626433832795;

template<class type>
type min( const type &A, const type &B ) {
  return A < B ? A : B;
}

template<class type>
type max( const type &A, const type &B ) {
  return A > B ? A : B;
}

template<class type>
type abs( const type &A ) {
  return A < 0 ? -A : A;
}

long long factorial( int I );

class point {
public:
  double X, Y;

  point( double X = 0, double Y = 0 ) : X(X), Y(Y) {
  }

  point operator+( const point &R ) const;
  point & operator+=( const point &R );
  point operator-( const point &R ) const;
  point & operator-=( const point &R );
  point & operator*( double Mul );
};

point & operator*( double Mul, point &P );

class grid : public std::vector<point> {
public:
  grid( void ) = default;
  grid( const std::vector<double> &Xs, const std::vector<double> &Ys );

  std::vector<double> X( void ) const;
  std::vector<double> Y( void ) const;
};

class grid_derivative : public std::vector<std::vector<double>> {
public:
  grid_derivative( void ) = default;
  grid_derivative( const grid &XY );
  grid_derivative( const std::initializer_list<std::vector<double>> &Rows );
  operator grid() const;

  std::vector<double> & operator[]( int Derivative );
  const std::vector<double> & operator[]( int Derivative ) const;
};

} // End of 'adv_math' namespace
