#pragma once

#include "../definitions.h"
#include "../function/function.h"

namespace adv_math {
namespace grids {

class regular : public grid {
public:
  regular( double L, double R, unsigned int N, const function &Func );
};

} // End of 'grids' namespace
} // End of 'adv_math' namespace
