#pragma once

#include "../stdafx.h"

#include <algorithm>

#include "../function/function.h"
#include "sde.h"

namespace adv_math {
namespace solvers {

class sde {
private:
  mutable int NumSteps;
protected:
  equations::sde System;
  double Precision;
  int Order;

public:
  virtual std::vector<std::vector<double>> values( double X, int Divs ) const = 0;

  virtual std::vector<double> at( double X, double Step ) const {
    return values(X, (int)((X - System.X0) / Step)).back();
  }

  std::vector<double> operator()( double X ) const {
    NumSteps = Order + 1;
    double
      Denum = (1 << Order) - 1,
      Step = (X - System.X0) / NumSteps;

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
