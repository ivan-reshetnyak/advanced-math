#pragma once

#include "../stdafx.h"

#include "solver.h"
#include "sle.h"

namespace adv_math {
namespace equations {

class solver_sle_triangular_lower : public solver<sle> {
public:
  solution solve( const sle &SLE ) const override {
    vector Roots(SLE.getH());
    const vector &Cs = SLE.getConstants();
    for (int Y = 0, H = SLE.getH(); Y < H; Y++) {
      double C = Cs[Y];
      for (int X = 0; X < Y; X++)
        C -= Roots[X] * SLE[X][Y];
      Roots[Y] = C / SLE[Y][Y];
    }

    return solution(Roots);
  }
};

class solver_sle_triangular_upper : public solver<sle> {
public:
  solution solve( const sle &SLE ) const override {
    vector Roots(SLE.getH());
    const vector &Cs = SLE.getConstants();
    for (int H = SLE.getH(), Y = H - 1; Y >= 0; Y--) {
      double C = Cs[Y];
      for (int X = H - 1; X > Y; X--)
        C -= Roots[X] * SLE[X][Y];
      Roots[Y] = C / SLE[Y][Y];
    }
    return solution(Roots);
  }
};

} // End of 'equations' namespace
} // End of 'adv_math' namespace
