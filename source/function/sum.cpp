#include "stdafx.h"

#include "sum.h"

namespace adv_math {
namespace func {

double sum::at( double X ) const {
  double y = 0;

  for (auto &f : Members)
    y += f(X);

  return y;
}

double sum::deriveAt( double X ) const  {
  double df = 0;

  for (auto &f : Members)
    df += f.derive(X);

  return df;
}

void sum::Add( const lambda &Func ) {
  Members.push_back(Func);
}

void sum::print( std::ostream &Stream ) const {
  for (auto i = Members.cbegin(); i < Members.cend(); i++)
    Stream << *i << (i + 1 < Members.cend() ? " + " : "");
}

}
}
