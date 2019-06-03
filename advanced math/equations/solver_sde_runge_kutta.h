#pragma once

#include "../stdafx.h"

#include "../function/function.h"
#include "solver_sde.h"

namespace adv_math {
namespace solvers {

template<int RKOrder>
class sde_runge_kutta : public sde {
protected:
  virtual std::vector<double> at( double X, double Step ) const override {
    std::vector<double> Y = System.Initials;
    int
      NoofSteps = (int)((X - System.X0) / Step),
      Size = System.Rows.size();
    X = System.X0;

    for (int StepNum = 0; StepNum < NoofSteps; StepNum++) {
      std::vector<std::vector<double>> k(Size, std::vector<double>(Order, 0));

      // Set k0
      for (int i = 0; i < Size; i++)
        k[i][0] = System.Rows[i](X, Y);

      // Set other k
      for (int i = 0; i < Size; i++)
        for (int Yk = 1; Yk < Order; Yk++) {
          auto Yc = Y;  // Copy Y
          // Displace
          for (int j = 0; j < Size; j++)
            for (int Xk = 0; Xk < Yk; Xk++)
              Yc[j] += Step * rk_coeff<RKOrder>::matrix(Xk, Yk) * k[j][Xk];
          k[i][Yk] = System.Rows[i](X + Step * rk_coeff<RKOrder>::node(Yk), Yc);
        }

      // Move
      for (int i = 0; i < Size; i++)
        for (int Stage = 0; Stage < Order; Stage++)
          Y[i] += Step * rk_coeff<RKOrder>::weight(Stage) * k[i][Stage];
      X += Step;
    }
    return Y;
  }

public:
  sde_runge_kutta( const equations::sde &Table, double Precision ) :
    sde(Table, Precision, RKOrder) {
  }
};

} // End of 'solvers' namespace
} // End of 'adv_math' namespace
