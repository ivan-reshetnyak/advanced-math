#include "stdafx.h"

//#include <unordered_map>

#include "integrator_chebyshev.h"

namespace adv_math {
namespace integr {

double chebyshev::abscissa( int N ) const {
  static
    std::vector<std::vector<double>> Pt = {
      {},                                                                    // 1
      { -0.57735, 0.57735 },                                                 // 2
      { -0.707107, 0, 0.57735 },                                             // 3
      { -0.794654, -0.187592, 0.187592, 0.794654 },                          // 4
      { -0.832498, -0.374541, 0, 0.374541, 0.832498 },                       // 5
      { -0.866247, -0.422519, -0.266635, 0.266635, 0.422519, 0.866247 },     // 6
      { -0.883862, -0.529657, -0.321912, 0, 0.321912, 0.529657, 0.883862 },  // 7
      {},                                                                    // 8
      { -0.911589, -0.601019, -0.528762, -0.167906, 0,
        0.167906, 0.528762, 0.601019, 0.911589 } };                          // 9

  if (NoofPoints < 2 || NoofPoints == 8 || NoofPoints > 9)
    throw std::exception("Chebyshev formulae works with 2-7 or 9 points only!");
  else
    return Pt[NoofPoints - 1][N - 1];
}

chebyshev::chebyshev( int NoofPoints ) : NoofPoints(NoofPoints) {
  if (NoofPoints < 2 || NoofPoints == 8 || NoofPoints > 9)
    throw std::exception("Chebyshev formulae works with 2-7 or 9 points only!");
}

void chebyshev::setNoofPoints( int NewNoofPoints ) {
  NoofPoints = NewNoofPoints;
}

double chebyshev::integrate( const function &Func, double LowerBound, double UpperBound ) const {
  double
    Sum = 0,
    Shift = 0.5 * (UpperBound + LowerBound),
    Stretch = 0.5 * (UpperBound - LowerBound);
  for (int i = 1; i <= NoofPoints; i++)
    Sum += Func(Shift + Stretch * abscissa(i));
  return Sum * (UpperBound - LowerBound) / NoofPoints;
}

} // End of 'integr' namespace
} // End of 'adv_math' namespace
