#pragma once

#include <vector>

#include "interpolator.h"
#include "../function/polynomial.h"

namespace adv_math {
namespace interp {

class polynomial_newton : public interpolator {
protected:
  grid Points;
  std::vector<double> DividedDifferences;

  virtual void print( std::ostream &Stream ) const override;
  virtual double at( double X ) const override;

private:
  double basisPolynomial( int K, double X ) const;

public:
  polynomial_newton( const grid &InputPoints );
  virtual void update( const grid &InputPoints ) override;
};

} // End of 'interp' namespace
} // End of 'adv_math' namespace
