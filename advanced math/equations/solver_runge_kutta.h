#pragma once

#include "../stdafx.h"

#include "../function/function.h"
#include "differential_coeffs.h"
#include "solver_differential.h"

namespace adv_math {
namespace solvers {

template<int RKOrder>
class runge_kutta : public differential {
protected:
  void print( std::ostream &Stream ) const override {
    Stream << "RK_" << Order;
  }

public:
  virtual double at( double X, double Step ) const override {
    double Y = Equation.P.Y;
    int NoofSteps = (int)((X - Equation.P.X) / Step);
    X = Equation.P.X;

    for (int StepNum = 0; StepNum < NoofSteps; StepNum++) {
      std::vector<double> k(Order);
      k[0] = Equation.F({X, Y});
      for (int Yk = 1; Yk < Order; Yk++) {
        auto Yc = Y;
        for (int Xk = 0; Xk < Yk; Xk++)
          Yc += Step * rk_coeff<RKOrder>::matrix(Xk, Yk) * k[Xk];
        k[Yk] = Equation.F({X + Step * rk_coeff<RKOrder>::node(Yk), Yc});
      }

      for (int Stage = 0; Stage < Order; Stage++)
        Y += Step * rk_coeff<RKOrder>::weight(Stage) * k[Stage];
      X += Step;
    }

    return Y;
  }


public:
  runge_kutta( const equations::differential &Eq, double Precision ) : differential(Eq, Precision, RKOrder) {
  }
};

} // End of 'solvers' namespace
} // End of 'adv_math' namespace
