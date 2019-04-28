#pragma once

#include "stdafx.h"

#include "function.h"

namespace adv_math {
namespace func {

template<class function_type,
  derived_from_function(function_type)>
class exp : public function {
public:
  exp( const function_type &Power ) : Power(Power) {
  }

protected:
  const function_type Power;

  virtual double at( double X ) const override {
    return ::exp(Power(X));
  }

  virtual double deriveAt( double X ) const override {
    return Power.derive(X) * ::exp(Power(X));
  }

  virtual void print( std::ostream &Stream ) const override {
    Stream << "e^(" << Power << ")";
  }
};

} // End of 'func' namespace
} // End of 'adv_math' namespace
