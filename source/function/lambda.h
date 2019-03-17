#pragma once

#include <functional>
#include <vector>

#include "function.h"

namespace adv_math {
namespace func {

class lambda : public function {

private:
  using f = std::function<double( double )>;
  using pf = std::function<void( std::ostream & )>;

public:
  lambda( const f &Func, const f &FuncDeriv, const pf &printFunc );
  lambda( const f &Func, const pf &printFunc );

protected:
  f Func, FuncDeriv;
  pf printFunc;

  virtual void print( std::ostream &Stream ) const override;
  virtual double at( double X ) const override;
  virtual double deriveAt( double X ) const override;
};

} // End of 'func' namespace
} // End of 'adv_math' namespace
