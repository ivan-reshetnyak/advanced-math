#pragma once

#include "../stdafx.h"

#include "solver.h"
#include "sle.h"

namespace adv_math {
namespace solvers {

class sle_inverse : public equations::solver<equations::sle> {
public:
  equations::solution solve( const equations::sle &SLE ) const override {
    if (SLE.determinant() == 0)
      return equations::solution(equations::solution::status::EMPTY);
    else
      return SLE.getConstants() * SLE.inversed();
  }
};

} // End of 'solvers' namespace
} // End of 'adv_math' namespace
