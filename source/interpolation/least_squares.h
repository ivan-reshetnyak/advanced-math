#pragma once

#include "../stdafx.h"

#include "interpolator.h"
#include "../function/polynomial.h"
#include "../equations/sle.h"
#include "../equations/solver_sle_inverse.h"

namespace adv_math {
namespace interp {

class least_squares : public interpolator {
private:
  std::vector<double> Weights;
  func::polynomial Poly;
  int Power;

protected:
  virtual void print( std::ostream &Stream ) const override;
  virtual double at( double X ) const override;

public:
  least_squares( const grid &InputPoints, const std::vector<double> &InputWeights, int Power );
  least_squares( const grid &InputPoints, int Power );
  virtual void update( const grid &Points ) override;
};

} // End of 'interp' namespace
} // End of 'adv_math' namespace
