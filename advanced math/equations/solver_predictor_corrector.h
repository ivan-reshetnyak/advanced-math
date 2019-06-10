#pragma once

#include "../stdafx.h"

#include "../function/function.h"
#include "solver_differential.h"
#include "differential_coeffs.h"

namespace adv_math {
namespace solvers {

template<class predictor, int PCOrder>
class predictor_corrector : public differential {
private:
  virtual void print( std::ostream &Stream ) const override {
  }

public:
  virtual double at( double X, double Step ) const override {
    auto Y = Equation.P.Y;
    int NoofSteps = (int)((X - Equation.P.X) / Step);
    NoofSteps = std::max(PCOrder, NoofSteps);
    Step = (X - Equation.P.X) / NoofSteps;
    X = Equation.P.X;

    std::vector<double> Predicted;
    predictor PredF(Equation, Precision);
    for (int StepNum = 1; StepNum <= NoofSteps; StepNum++)
      Predicted.push_back(PredF.at(X + Step * StepNum, Step));

    for (int StepNum = PCOrder - 1; StepNum < NoofSteps; StepNum++) {
      X += Step;
      double Res = Predicted[StepNum - 1];
      for (int j = 0; j < PCOrder; j++)
        Res += Step / pc_coeff<PCOrder>::denum() * pc_coeff<PCOrder>::weight(j) *
          Equation.F({ X - j * Step, Predicted[StepNum - j] });
      Predicted[StepNum] = Res;
    }

    return Predicted.back();
  }

public:
  predictor_corrector( const equations::differential &Eq, double Precision ) :
    differential(Eq, Precision, PCOrder) {
  }
};


} // End of 'solvers' namespace
} // End of 'adv_math' namespace
