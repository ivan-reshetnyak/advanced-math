#pragma once

#include "../stdafx.h"

#include <cmath>

#include "function.h"

namespace adv_math {
namespace func {

template<class func, derived_from_function(func)>
class sin : public function {
  public:
  sin( const func &Func ) : Func(Func) {
  }

private:
  func Func;

  double at( double X ) const override {
    return ::sin(Func(X));
  }

  double deriveAt( double X ) const override {
    return Func.derive(X) * ::cos(Func(X));
  }

  virtual void print( std::ostream &Stream ) const override {
    Stream << "sin(" << Func << ")";
  }
};

template<class func, derived_from_function(func)>
class cos : public function {
  public:
  cos( const func &Func ) : Func(Func) {
  }

private:
  func Func;

  double at( double X ) const override {
    return ::cos(Func(X));
  }

  double deriveAt( double X ) const override {
    return -Func.derive(X) * ::sin(Func(X));
  }

  virtual void print( std::ostream &Stream ) const override {
    Stream << "cos(" << Func << ")";
  }
};

} // End of 'func' namespace
} // End of 'adv_math' namespace
