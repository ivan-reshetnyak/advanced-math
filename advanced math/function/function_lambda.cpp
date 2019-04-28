#include "stdafx.h"

#include "function_lambda.h"

namespace adv_math {
namespace func {

lambda::lambda( const lambda::f &Func, const lambda::f &FuncDeriv, const lambda::pf &printFunc ) :
    Func(Func), FuncDeriv(FuncDeriv), printFunc(printFunc) {
}

lambda::lambda( const lambda::f &Func, const lambda::pf &printFunc ) :
    Func(Func), FuncDeriv([]( double ) -> double { return 0; }), printFunc(printFunc) {
}

double lambda::at( double X ) const {
  return Func(X);
}

double lambda::deriveAt( double X ) const  {
  return FuncDeriv(X);
}

void lambda::print( std::ostream &Stream ) const {
  printFunc(Stream);
}

} // End of 'func' namespace
} // End of 'adv_math' namespace
