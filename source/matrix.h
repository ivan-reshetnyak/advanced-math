#pragma once

#include "stdafx.h"

#include "definitions.h"
#include "vector.h"

namespace adv_math {

class matrix {
private:
  using col_t = vector;
  using row_t = vec<col_t>;
  row_t Data;
  mutable bool NeedUpdate;
  mutable double Determinant;
  friend std::ostream & operator<<( std::ostream &, const matrix & );

public:
  matrix( int W = 1, int H = 1 );
  matrix( const row_t &MIn );
  int getW( void ) const;
  int getH( void ) const;
  col_t & operator[]( int X );
  const col_t & operator[]( int X ) const;
  matrix minor( int X, int Y ) const;
  matrix adjoint( void ) const;
  double determinant( void ) const;
  matrix & inverse( void );
  matrix inversed( void ) const;
  matrix operator*( double C ) const;
  matrix & operator*=( double C);
  matrix operator/( double C ) const;
  matrix & operator/=( double C);
  matrix & slice( const std::pair<int, int> &P1, const std::pair<int, int> &P2 );
  matrix sliced( const std::pair<int, int> &P1, const std::pair<int, int> &P2 ) const;
  matrix & square( void );
};

std::ostream & operator<<( std::ostream &Stream, const matrix &Matr );
vector operator*( const vector &Vec, const matrix &Matr );
vector & operator*=( vector &Vec, const matrix &Matr );

} // End of 'adv_math' namespace
