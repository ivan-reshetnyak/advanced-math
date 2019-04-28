#pragma once

#include "../stdafx.h"

#include "solver.h"
#include "sle.h"

namespace adv_math {
namespace equations {

class solver_sle_inverse : public solver<sle> {
public:
  solution solve( const sle &SLE ) const override {
    if (SLE.determinant() == 0)
      return solution(solution::status::EMPTY);
    else
      return SLE.getConstants() * SLE.inversed();
  }
};

} // End of 'equations' namespace
} // End of 'adv_math' namespace
