#pragma once

#include "../stdafx.h"

#include "integrator.h"

namespace adv_math {
namespace integr {

class chebyshev : public integrator {
private:
  int NoofPoints;
  double abscissa( int N ) const;

public:
  chebyshev( int NoofPoints = 2 );
  void setNoofPoints( int NewNoofPoints );
  double integrate( const function &Func, double LowerBound, double UpperBound ) const override;
};

} // End of 'integr' namespace
} // End of 'adv_math' namespace
