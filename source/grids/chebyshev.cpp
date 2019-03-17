#include "stdafx.h"

#include "chebyshev.h"

namespace adv_math {
namespace grids {

chebyshev::chebyshev( double L, double R, unsigned int N, const function &Func ) {
  point Cur = { 0, 0 };

  for (unsigned int i = 1; i <= N; i++) {
    Cur.X = -(0.5 * (L + R) + 0.5 * (R - L) * cos((2. * i - 1.) / (2. * N) * Pi));
    Cur.Y = Func(Cur.X);
    push_back(Cur);
  }
}

} // End of 'grids' namespace
} // End of 'adv_math' namespace
