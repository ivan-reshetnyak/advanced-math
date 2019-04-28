#pragma once

#include "../stdafx.h"

#include "integrator.h"

namespace adv_math {
namespace integr {

class chebyshev : public integrator {
private:
  double Tolerance;
  mutable double PrevError;
  mutable int PrevDivs;

  double step( const function &Func, double LowerBound, double UpperBound, double PrevVal, int Divs ) const;

public:
  chebyshev( double Tolerance );
  void setTolerance( double Tolerance );
  double integrate( const function &Func, double LowerBound, double UpperBound ) const override;
  double runSteps( const function &Func, double LowerBound, double UpperBound, int Steps ) const;
  double getError( void ) const;
  int getDivisions( void ) const;
};

} // End of 'integr' namespace
} // End of 'adv_math' namespace
