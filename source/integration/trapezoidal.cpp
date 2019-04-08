#include "stdafx.h"

//#include <unordered_map>

#include "trapezoidal.h"

namespace adv_math {
namespace integr {

trapezoidal::trapezoidal( double Tolerance ) : Tolerance(Tolerance) {
}

void trapezoidal::setTolerance( double NewTolerance ) {
  Tolerance = NewTolerance;
}

double trapezoidal::integrate( const function &Func, double LowerBound, double UpperBound ) {
  //std::unordered_map<double, double> FVal;
  int Divs = 1;
  double Error, PrevVal = 0;

  do {
    double X = LowerBound, DX = (UpperBound - LowerBound) / Divs, Val = 0;

    for (int i = 0; i < Divs; i++) {
      Val += DX * 0.5 * (Func(X) + Func(X + DX));
      X += DX;
    }

    Error = 1. / 3. * std::abs(Val - PrevVal);
    PrevVal = Val;
    Divs *= 2;
  } while (Error > Tolerance);

  return PrevVal;
}

} // End of 'integr' namespace
} // End of 'adv_math' namespace
