#pragma once

#include "../definitions.h"
#include "../function/function.h"

namespace adv_math {
namespace grids {

class chebyshev : public grid {
public:
  chebyshev( double L, double R, unsigned int N, const function &Func );
};

} // End of 'grids' namespace
} // End of 'adv_math' namespace
