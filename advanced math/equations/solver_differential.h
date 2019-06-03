#pragma once

#include "../stdafx.h"

#include "../function/function.h"
#include "equation_differential.h"

namespace adv_math {
namespace solvers {

class differential : public function {
protected:
  equations::differential Equation;
  double Precision;
  int Order;
  mutable int NumSteps;

  virtual void print( std::ostream &Stream ) const override = 0;
  virtual double at( double X, double Step ) const = 0;

  double at( double X ) const final {
    double
      Denum = (1 << Order) - 1,
      Step = X - Equation.P.X,
      YPrev = 0, Y = at(X, Step);
    NumSteps = 1;

    while (abs(YPrev - Y) > Precision) {
      YPrev = Y;
      Step *= 0.5;
      Y = at(X, Step);
      NumSteps *= 2;
    }

    return Y;
  }

public:
  int getNumSteps( void ) const {
    return NumSteps;
  }

  differential( const equations::differential &Eq, double Precision, int Order ) :
    Equation(Eq), Precision(Precision), Order(Order) {
  }
};

} // End of 'solvers' namespace
} // End of 'adv_math' namespace
