#pragma once

#include "../stdafx.h"

#include "integrator.h"

namespace adv_math {
namespace integr {

class trapezoidal : public integrator {
private:
  double Tolerance;
  mutable double PrevError;
  mutable int PrevDivs;

public:
  trapezoidal( double Tolerance );
  void setTolerance( double Tolerance );
  double integrate( const function &Func, double LowerBound, double UpperBound ) const override;
  double getError( void ) const;
  int getDivisions( void ) const;
};

} // End of 'integr' namespace
} // End of 'adv_math' namespace
