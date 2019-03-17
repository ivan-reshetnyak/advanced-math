#include "stdafx.h"

#include "regular.h"

namespace adv_math {
namespace grids {

regular::regular( double L, double R, unsigned int N, const function &Func ) {
  point Cur = { L, 0 }, Delta = { (R - L) / (N - 1), 0 };

  for (unsigned int i = 0; i < N; i++) {
    Cur.Y = Func(Cur.X);
    push_back(Cur);
    Cur += Delta;
  }
}

} // End of 'grids' namespace
} // End of 'adv_math' namespace
