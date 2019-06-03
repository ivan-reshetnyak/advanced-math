#pragma once

#include "../stdafx.h"

#include "../function/function.h"
#include "equation_differential.h"

namespace adv_math {
namespace equations {

template<int NoofStages>
class solver_runge_kutta {
protected:
  int NoofSteps;
  mutable double H;
  const differential_first_order &Equation;

  virtual double matrix( int X, int Y ) const = 0;
  virtual double weight( int X ) const = 0;
  virtual double node( int Y ) const = 0;

  /*
  double k( int Stage, double H, double X, double Y ) {
    if (Stage == 0)
      return Equation(X, Y);

    
  }
  */

public:
  virtual std::valarray<double> operator()( double X ) const {
    auto Y = Equation.P.Y;
    H = (X - Equation.P.X) / NoofSteps;
    X = Equation.P.X;

    for (int Step = 0; Step < NoofSteps; Step++) {
      std::vector<double> k(NoofStages);
      k[0] = Equation.F({X, Y});
      for (int Yk = 1; Yk < NoofStages; Yk++) {
        auto Yc = Y;
        for (int Xk = 0; Xk < Yk; Xk++)
          Yc += H * matrix(Xk, Yk) * k[Xk];
        k[Yk] = Equation.F({X + H * node(Yk), Yc});
      }

      for (int Stage = 0; Stage < NoofStages; Stage++)
        Y += H * weight(Stage) * k[Stage];
      X += H;
    }

    return Y;
  }

  solver_runge_kutta( const differential_first_order &Eq, int Steps ) : NoofSteps(Steps), Equation(Eq) {
  }
};

class solver_RK4 : public solver_runge_kutta<4> {
private:
  double matrix( int X, int Y ) const final {
    static double A[3][4] = {
      {  .5,  .0,  .0,  .0 },
      {  .0,  .5,  .0,  .0 },
      {  .0,  .0, 1.0,  .0 } };
    return A[Y - 1][X];
  }

  double weight( int X ) const final {
    static double W[] = { 1. / 6, 2. / 6, 2. / 6, 1. / 6 };
    return W[X];
  }

  double node( int Y ) const final {
    static double N[] = { 0.5, 0.5, 1 };
    return N[Y - 1];
  }

public:
  solver_RK4( const differential_first_order &Eq, int Steps ) : solver_runge_kutta(Eq, Steps) {
  }
};

class solver_euler_cauchy : public solver_runge_kutta<2> {
private:
  double matrix( int X, int Y ) const final {
    return 1;
  }

  double weight( int X ) const final {
    return 0.5;
  }

  double node( int Y ) const final {
    return 1;
  }

public:
  solver_euler_cauchy ( const differential_first_order &Eq, int Steps ) : solver_runge_kutta(Eq, Steps) {
  }
};

} // End of 'equations' namespace
} // End of 'adv_math' namespace
