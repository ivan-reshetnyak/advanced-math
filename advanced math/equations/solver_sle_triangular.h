#pragma once

#include "../stdafx.h"

#include "solver.h"
#include "sle.h"

namespace adv_math {
namespace solvers {

class sle_triangular_lower : public equations::solver<equations::sle> {
public:
  equations::solution solve( const equations::sle &SLE ) const override {
    vector Roots(SLE.getH());
    const vector &Cs = SLE.getConstants();
    for (int Y = 0, H = SLE.getH(); Y < H; Y++) {
      double C = Cs[Y];
      for (int X = 0; X < Y; X++)
        C -= Roots[X] * SLE[X][Y];
      Roots[Y] = C / SLE[Y][Y];
    }

    return equations::solution(Roots);
  }
};

class sle_triangular_upper : public equations::solver<equations::sle> {
public:
  equations::solution solve( const equations::sle &SLE ) const override {
    vector Roots(SLE.getH());
    const vector &Cs = SLE.getConstants();
    for (int H = SLE.getH(), Y = H - 1; Y >= 0; Y--) {
      double C = Cs[Y];
      for (int X = H - 1; X > Y; X--)
        C -= Roots[X] * SLE[X][Y];
      Roots[Y] = C / SLE[Y][Y];
    }
    return equations::solution(Roots);
  }
};

} // End of 'solvers' namespace
} // End of 'adv_math' namespace
