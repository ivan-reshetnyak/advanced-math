#pragma once

#include "../stdafx.h"

#include "../function/function.h"
#include "solver_differential.h"

namespace adv_math {
namespace solvers {

class runge_kutta : public differential {
protected:
  virtual double matrix( int X, int Y ) const = 0;
  virtual double weight( int X ) const = 0;
  virtual double node( int Y ) const = 0;

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
          Yc += Step * matrix(Xk, Yk) * k[Xk];
        k[Yk] = Equation.F({X + Step * node(Yk), Yc});
      }

      for (int Stage = 0; Stage < Order; Stage++)
        Y += Step * weight(Stage) * k[Stage];
      X += Step;
    }

    return Y;
  }

  void print( std::ostream &Stream ) const override {
    Stream << "RK_" << Order;
  }

public:
  runge_kutta( const equations::differential &Eq, double Precision, int Order ) : differential(Eq, Precision, Order) {
  }
};

class RK4 : public runge_kutta {
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
  RK4( const equations::differential &Eq, double Precision ) : runge_kutta(Eq, Precision, 4) {
  }
};

class euler_cauchy : public runge_kutta {
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
  euler_cauchy( const equations::differential &Eq, double Precision ) : runge_kutta(Eq, Precision, 2) {
  }
};

} // End of 'solvers' namespace
} // End of 'adv_math' namespace
