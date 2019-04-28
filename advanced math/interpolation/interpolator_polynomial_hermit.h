#pragma once

#include "../stdafx.h"

#include "interpolator.h"
#include "../function/function_polynomial.h"

namespace adv_math {
namespace interp {

class polynomial_hermit : public interpolator {
protected:
  std::vector<std::vector<double>> DividedDifferences;
  grid_derivative Points;

  virtual void print( std::ostream &Stream ) const override;
  virtual double at( double X ) const override;

private:
  double basisPolynomial( int K, double X ) const;
  virtual void update( void );

public:
  /***
   * Input points is a list of grid points (X-es), f(X), f'(X), f''(X), ...
   ***/
  polynomial_hermit( const grid_derivative &InputPoints );
  virtual void update( const grid &InputPoints ) override;
  virtual void update( const grid_derivative &InputPoints );
};

} // End of 'interp' namespace
} // End of 'adv_math' namespace
