#pragma once

#include "../stdafx.h"

#include <functional>

#include "../definitions.h"

namespace adv_math {
namespace equations {

class differential_first_order {
private:
  using func3d = std::function<double ( double, double )>;
  func3d Func;     // y' = F(x, y)
  point Initial;  // x0, y0

public:
  const func3d &F;
  const point &P;

  differential_first_order( const func3d &Function, const point &Initials ) : Func(Function), Initial(Initials),
    F(Func), P(Initial) {
  }

  differential_first_order( const differential_first_order &RV ) : Func(RV.Func), Initial(RV.Initial),
    F(Func), P(Initial) {
  }

  differential_first_order & operator=( const differential_first_order &RV ) {
    Func = RV.Func;
    Initial = RV.Initial;
    return *this;
  }
};

} // End of 'equations' namespace
} // End of 'adv_math' namespace
