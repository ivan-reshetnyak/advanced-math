#pragma once

#include "../stdafx.h"

#include "function.h"

namespace adv_math {
namespace func {

class constant : public derivable<constant> {
public:
  constant( double A ) : Value(A) {
  }

private:
  double Value;

  double at( double X ) const override {
    return Value;
  }

  double deriveAt( double X ) const override {
    return 0;
  }

  constant _derivative( void ) const override {
    return constant(0);
  }

  virtual void print( std::ostream &Stream ) const override {
    Stream << Value;
  }
};

class x : public derivable<constant> {
public:
  x( void ) {
  }

private:
  double at( double X ) const override {
    return X;
  }

  double deriveAt( double X ) const override {
    return 1;
  }

  constant _derivative( void ) const override {
    return constant(1);
  }

  virtual void print( std::ostream &Stream ) const override {
    Stream << "x";
  }
};

template<class func1, class func2>
class sum : public derivable<sum<typename func1::derivative_t, typename func2::derivative_t>> {
public:
  sum( const func1 &F1, const func2 &F2 ) : Func1(F1), Func2(F2) {
  }

private:
  func1 Func1;
  func2 Func2;

  double at( double X ) const override {
    return Func1(X) + Func2(X);
  }

  double deriveAt( double X ) const override {
    return Func1.derive(X) + Func2.derive(X);
  }

  derivative_t _derivative( void ) const override {
    return derivative_t(Func1.derivative() + Func2.derivative());
  }

  virtual void print( std::ostream &Stream ) const override {
    Stream << "(" << Func1 << " + " << Func2 << ")";
  }
};

template<class func1, class func2>
class difference : public function {
public:
  difference( const func1 &F1, const func2 &F2 ) : Func1(F1), Func2(F2) {
  }

private:
  func1 Func1;
  func2 Func2;

  double at( double X ) const override {
    return Func1(X) - Func2(X);
  }

  double deriveAt( double X ) const override {
    return Func1.derive(X) - Func2.derive(X);
  }

  virtual void print( std::ostream &Stream ) const override {
    Stream << "(" << Func1 << " - " << Func2 << ")";
  }
};

template<class func1, class func2>
class product : public function {
public:
  product( const func1 &F1, const func2 &F2 ) : Func1(F1), Func2(F2) {
  }

private:
  func1 Func1;
  func2 Func2;

  double at( double X ) const override {
    return Func1(X) * Func2(X);
  }

  double deriveAt( double X ) const override {
    return Func1.derive(X) * Func2(X) + Func1(X) * Func2.derive(X);
  }

  virtual void print( std::ostream &Stream ) const override {
    Stream << "(" << Func1 << " * " << Func2 << ")";
  }
};

template<class func1, class func2>
class ratio : public function {
public:
  ratio( const func1 &F1, const func2 &F2 ) : Func1(F1), Func2(F2) {
  }

private:
  func1 Func1;
  func2 Func2;

  double at( double X ) const override {
    return Func1(X) / Func2(X);
  }

  double deriveAt( double X ) const override {
    return (Func2.derive(X) * Func1(X) - Func1.derive(X) * Func2(X)) / Func2(X) / Func2(X);
  }

  virtual void print( std::ostream &Stream ) const override {
    Stream << "(" << Func1 << " / " << Func2 << ")";
  }
};

template<class func1, class func2>
sum<func1, func2> operator+( const func1 &F1, const func2 &F2 ) {
  return sum<func1, func2>(F1, F2);
}

template<class func1, class func2>
difference<func1, func2> operator-( const func1 &F1, const func2 &F2 ) {
  return difference<func1, func2>(F1, F2);
}

template<class func1, class func2>
product<func1, func2> operator*( const func1 &F1, const func2 &F2 ) {
  return product<func1, func2>(F1, F2);
}

template<class func1, class func2>
ratio<func1, func2> operator/( const func1 &F1, const func2 &F2 ) {
  return ratio<func1, func2>(F1, F2);
}

} // End of 'func' namespace
} // End of 'adv_math' namespace
