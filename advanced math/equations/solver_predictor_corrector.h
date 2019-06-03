#pragma once

#include "../stdafx.h"

#include "../function/function.h"
#include "solver_differential.h"

namespace adv_math {
namespace solvers {

template<class predictor, class corrector>
class predictor_corrector : public differential {
private:
  using dif_eq = equations::differential;
  int NoofSteps;
  const dif_eq &Equation;

  virtual void print( std::ostream &Stream ) const override {
  }

  virtual double at( double X, double Step ) const override {
    auto Y = Equation.P.Y;
    int NoofSteps = (int)((X - Equation.P.X) / Step);
    X = Equation.P.X;

    for (int StepNum = 0; StepNum < NoofSteps; StepNum++) {
      X += Step;
      double PredY = predictor(dif_eq(Equation.F, point(X, Y)), 1)(X + Step);
      point Midpoint = 0.5 * (point(X, Y) + point(X + Step, PredY));
      Y = corrector(dif_eq(Equation.F, Midpoint), 1)(X + Step);
    }

    return Y;
  }

public:
  predictor_corrector( const equations::differential &Eq, double Precision ) : differential(Eq, Precision) {
  }
};

} // End of 'solvers' namespace
} // End of 'adv_math' namespace
