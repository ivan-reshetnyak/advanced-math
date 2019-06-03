#pragma once

#include "../stdafx.h"

#include "solver.h"
#include "solver_sle_triangular.h"
#include "sle.h"

namespace adv_math {
namespace solvers {

class sle_lu : public equations::solver<equations::sle> {
public:
  equations::solution solve( const equations::sle &SLE ) const override {
    int Size = SLE.getW();
    matrix L = matrix::identity(Size), U(Size, Size);
    const matrix &A = SLE;

    /*
    for (X = 0; X < Size; X++)
      U[X][0] = A[X][0];
    for (Y = 0; Y < Size; Y++)
      L[0][Y] = A[0][Y] / U[0][0];
      */

    int K;
    for (int M = 0; M < Size; M++)
      for (int I = M; I < Size; I++) {
        U[I][M] = A[I][M];
        for (K = 0; K < M; K++)
          U[I][M] -= L[K][M] * U[I][K];

        if (I > M) {
          L[M][I] = A[M][I];
          for (K = 0; K < M; K++)
            L[M][I] -= L[K][I] * U[M][K];
          L[M][I] /= U[M][M];
        }
      }

    equations::solution SolL = sle_triangular_lower().solve(equations::sle(L, SLE.getConstants()));

    return sle_triangular_upper().solve(equations::sle(U, SolL.getRoots()));
  }
};

} // End of 'solvers' namespace
} // End of 'adv_math' namespace
