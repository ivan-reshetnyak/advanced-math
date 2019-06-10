#pragma once

#include "../stdafx.h"

#include "equation_boundary.h"

namespace adv_math {
namespace solvers {

class boundary {
protected:
  equations::boundary Equation;

public:
  virtual std::vector<double> Solve( int Divisions ) const = 0;

  boundary( const equations::boundary &Eq ) : Equation(Eq) {
  }
};

} // End of 'solvers' namespace
} // End of 'adv_math' namespace
