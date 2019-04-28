#include "stdafx.h"

//#include <unordered_map>

#include "integrator_chebyshev.h"

namespace adv_math {
namespace integr {

chebyshev::chebyshev( double Tolerance ) : Tolerance(Tolerance), PrevDivs(1) {
}

void chebyshev::setTolerance( double NewTolerance ) {
  Tolerance = NewTolerance;
}

double chebyshev::step( const function &Func, double LowerBound, double UpperBound, double PrevVal, int Divs ) const {
  double X = LowerBound, DX = (UpperBound - LowerBound) / Divs, Val = 0;

  for (int i = 0; i < Divs; i++) {
    Val += DX * 0.5 * (Func(X) + Func(X + DX));
    X += DX;
  }

  PrevError = 1. / 3. * std::abs(Val - PrevVal);

  return Val;
}

double chebyshev::integrate( const function &Func, double LowerBound, double UpperBound ) const {
  int Divs = 1;
  double PrevVal = 0;

  do {
    PrevVal = step(Func, LowerBound, UpperBound, PrevVal, Divs);
    Divs *= 2;
  } while (Divs <= 2 || PrevError > Tolerance);

  PrevDivs = Divs / 2;
  return PrevVal;
}

double chebyshev::runSteps( const function &Func, double LowerBound, double UpperBound, int Steps ) const {
  int Divs = 1;
  double PrevVal = 0;

  for (int Step = 0; Step < Steps; Step++) {
    PrevVal = step(Func, LowerBound, UpperBound, PrevVal, Divs);
    Divs *= 2;
  }

  PrevDivs = Divs / 2;
  return PrevVal;
}

int chebyshev::getDivisions( void ) const {
  return PrevDivs;
}

double chebyshev::getError( void ) const {
  return PrevError;
}

} // End of 'integr' namespace
} // End of 'adv_math' namespace
