#pragma once

#include "../stdafx.h"

#include "../function/function.h"
#include "solver_sde.h"

namespace adv_math {
namespace solvers {

template<class predictor, int PCOrder>
class sde_predictor_corrector : public sde {
protected:
  virtual std::vector<std::vector<double>> values( double X, int Divs ) const override {
    std::vector<double> Y = System.Initials;
    int
      NoofSteps = Divs,
      Size = System.Rows.size();
    double Step = (X - System.X0) / NoofSteps;
    X = System.X0;

    std::vector<std::vector<double>> Predicted(NoofSteps + 1, std::vector<double>(Size, 0));
    Predicted[0] = Y;
    predictor PredF(System, Precision);
    for (int StepNum = 1; StepNum < PCOrder; StepNum++)
      Predicted[StepNum] = PredF.at(X + Step * StepNum, Step);

    for (int StepNum = PCOrder; StepNum <= NoofSteps; StepNum++) {
      X += Step;
      for (int i = 0; i < Size; i++) {
        auto Res = Predicted[StepNum - 1][i];
        for (int j = 1; j <= PCOrder; j++)
          Res += Step / pc_coeff<PCOrder>::denum() * pc_coeff<PCOrder>::weight(j - 1) *
            System.Rows[i](X - j * Step, Predicted[StepNum - j]);
        Predicted[StepNum][i] = Res;
      }
    }

    return Predicted;
  }

public:
  sde_predictor_corrector( const equations::sde &Table, double Precision ) :
    sde(Table, Precision, PCOrder) {
  }
};

} // End of 'solvers' namespace
} // End of 'adv_math' namespace
