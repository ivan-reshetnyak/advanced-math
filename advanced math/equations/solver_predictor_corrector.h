#pragma once

#include "../stdafx.h"

#include "../function/function.h"
#include "equation_differential.h"

namespace adv_math {
namespace equations {

template<class predictor, class corrector>
class solver_predictor_corrector : public function {
private:
  using dif_eq = differential_first_order;
  int NoofSteps;
  const differential_first_order &Equation;

  virtual void print( std::ostream &Stream ) const override {
  }

  virtual double at( double X ) const override {
    double
      Y = Equation.P.Y,
      H = (X - Equation.P.X) / NoofSteps;
    X = Equation.P.X;

    for (int Step = 0; Step < NoofSteps; Step++) {
      X += H;
      double PredY = predictor(dif_eq(Equation.F, point(X, Y)), 1)(X + H);
      point Midpoint = 0.5 * (point(X, Y) + point(X + H, PredY));
      Y = corrector(dif_eq(Equation.F, Midpoint), 1)(X + H);
    }

    return Y;
  }

public:
  solver_predictor_corrector( const differential_first_order &Eq, int Steps ) : NoofSteps(Steps), Equation(Eq) {
  }
};

} // End of 'equations' namespace
} // End of 'adv_math' namespace
