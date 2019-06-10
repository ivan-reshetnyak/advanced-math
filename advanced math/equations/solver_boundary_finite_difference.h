#pragma once

#include "../stdafx.h"

#include "solver_boundary.h"
#include "solver_sle_lu.h"

namespace adv_math {
namespace solvers {

class finite_difference : public boundary {
public:
  std::vector<double> Solve( int N ) const final {
    double
      H = (Equation.Bound.second.X - Equation.Bound.first.X) / N,
      X0 = Equation.Bound.first.X;
    matrix M(N + 1, N + 1);
    vector V(N + 1, 0);

    for (int i = 1; i < N; i++) {
      double Xi = X0 + H * i;
      M[i - 1][i - 1] = 1 - Equation.P(Xi) * H * 0.5;  // Ai * yi-1
      M[i][i - 1] = -(2 - Equation.Q(Xi) * H * H);     // -Ci * yi
      M[i + 1][i - 1] = 1 + Equation.P(Xi) * H * 0.5;  // Bi * yi+1
      V[i - 1] = Equation.F(Xi) * H * H;
    }
    M[0][N - 1] = 1;
    V[N - 1] = Equation.Bound.first.Y;
    M[N][N] = 1;
    V[N] = Equation.Bound.second.Y;

    equations::sle Sys(M, V);
    return solvers::sle_lu().solve(Sys).getRoots();
  }

  finite_difference( const equations::boundary &Eq ) : boundary(Eq) {
  }
};

} // End of 'solvers' namespace
} // End of 'adv_math' namespace
