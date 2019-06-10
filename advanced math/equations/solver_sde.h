#pragma once

#include "../stdafx.h"

#include <algorithm>

#include "../function/function.h"
#include "sde.h"

namespace adv_math {
namespace solvers {

class sde {
protected:
  equations::sde System;
  double Precision;
  int Order;
  mutable int NumSteps;

  virtual std::vector<double> at( double X, double Step ) const = 0;

public:
  std::vector<double> operator()( double X ) const {
    double
      Denum = (1 << Order) - 1,
      Step = X - System.X0;

    std::vector<double>
      YPrev(System.Rows.size(), 0),
      Y = at(X, Step);
    auto getMaxError = [&Y, &YPrev]( void ) -> double {
        double Max = 0;
        for (int i = 0, Size = Y.size(); i < Size; i++)
          Max = std::max(Max, abs(Y[i] - YPrev[i]));
        //std::cout << Max << std::endl;
        return Max;
      };

    NumSteps = 1;

    while (getMaxError() > Precision) {
      YPrev = Y;
      Step *= 0.5;
      Y = at(X, Step);
      NumSteps *= 2;
    }

    return Y;
  }

  int getNumSteps( void ) const {
    return NumSteps;
  }

  int getOrder( void ) const {
    return Order;
  }

  sde( const equations::sde &Table, double Precision, int Order ) :
    System(Table), Precision(Precision), Order(Order) {
  }
};

} // End of 'solvers' namespace
} // End of 'adv_math' namespace
