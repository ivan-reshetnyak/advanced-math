#pragma once

#include "../stdafx.h"

#include "integrator.h"

namespace adv_math {
namespace integr {

class trapezoidal : public integrator {
private:
  double Tolerance;

public:
  trapezoidal( double Tolerance );
  void setTolerance( double Tolerance );
  double integrate( const function &Func, double LowerBound, double UpperBound ) override;
};

} // End of 'integr' namespace
} // End of 'adv_math' namespace
