#pragma once

#include "../stdafx.h"

#include "../function/function.h"

namespace adv_math {

class integrator {
public:
  integrator( void ) = default;
  virtual double integrate( const function &Func, double LowerBound, double UpperBound ) = 0;
};

} // End of 'adv_math' namespace
