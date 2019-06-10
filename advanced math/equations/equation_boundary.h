#pragma once

#include "../stdafx.h"

#include <valarray>
#include <memory>

#include "../function/function.h"
#include "../definitions.h"

namespace adv_math {
namespace equations {

class boundary {
private:
  std::shared_ptr<function> PPtr, QPtr, FPtr;  // y'' + P(x)y' + Q(x)y = F(x)
  std::pair<point, point> Bounds;              // x0, y0

public:
  const function &P, &Q, &F;
  const std::pair<point, point> &Bound;

  boundary( function *PFunc, function *QFunc, function *FFunc, const std::pair<point, point> &InBounds ) :
    PPtr(PFunc), QPtr(QFunc), FPtr(FFunc), Bounds(InBounds),
    P(*PPtr), Q(*QPtr), F(*FPtr), Bound(Bounds) {
  }

  boundary( const boundary &RV ) :
    PPtr(RV.PPtr), QPtr(RV.QPtr), FPtr(RV.FPtr), Bounds(RV.Bound),
    P(*PPtr), Q(*QPtr), F(*FPtr), Bound(Bounds) {
  }
};

} // End of 'equations' namespace
} // End of 'adv_math' namespace
