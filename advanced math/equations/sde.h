#pragma once

#include "../stdafx.h"

#include <vector>
#include <valarray>
#include <functional>

namespace adv_math {
namespace equations {

class sde {
private:
  using function = std::function<double( double, const std::vector<double> )>;
  using table = std::vector<function>;
  table RowsData;
  std::vector<double> InitialsData;
  double X0Data;

public:
  const table &Rows;
  const std::vector<double> &Initials;
  const double &X0;

  sde( const table &InRows, double X, const std::vector<double> &Init ) :
    RowsData(InRows), X0Data(X), InitialsData(Init),
    Rows(RowsData), Initials(InitialsData), X0(X0Data) {
  }

  sde( const sde &RV ) : Rows(RowsData), Initials(InitialsData), X0(X0Data),
    RowsData(RV.RowsData), InitialsData(RV.InitialsData), X0Data(RV.X0Data) {
  }
};

} // End of 'equations' namespace
} // End of 'adv_math' namespace
