#pragma once

#include "../stdafx.h"

namespace adv_math {

template<int Order>
class rk_coeff {
public:
  static double matrix( int X, int Y ) = 0;
  static double weight( int X ) = 0;
  static double node( int Y ) = 0;
};

template<>
class rk_coeff<4> {
public:
  static double matrix( int X, int Y ) {
    static double A[3][4] = {
      {  .5,  .0,  .0,  .0 },
      {  .0,  .5,  .0,  .0 },
      {  .0,  .0, 1.0,  .0 } };
    return A[Y - 1][X];
  }

  static double weight( int X ) {
    static double W[] = { 1. / 6, 2. / 6, 2. / 6, 1. / 6 };
    return W[X];
  }

  static double node( int Y ) {
    static double N[] = { 0.5, 0.5, 1 };
    return N[Y - 1];
  }
};

template<>
class rk_coeff<2> {
public:
  static double matrix( int X, int Y ) {
    return 1;
  }

  static double weight( int X ) {
    return 0.5;
  }

  static double node( int Y ) {
    return 1;
  }
};

} // End of 'adv_math' namespace
