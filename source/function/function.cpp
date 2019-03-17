#include "stdafx.h"

#include "function.h"

namespace adv_math {

double function::f( double X ) const {
  return (*this)(X);
}

double function::operator()( double X ) const {
  return at(X);
}

std::vector<double> function::operator()( const std::initializer_list<double> &Points ) const {
  std::vector<double> res(Points.size());
  int i = 0;
  for (const auto &it : Points)
    res[i++] = f(it);

  return res;
}

std::vector<double> function::operator()( const std::vector<double> &Points ) const {
  std::vector<double> res(Points.size());
  int i = 0;
  for (const auto &it : Points)
    res[i++] = f(it);

  return res;
}

double function::derive( double X ) const {
  return deriveAt(X);
}

double function::deriveAt( double X ) const {
  return 0;
}

/*void function::derivative( function &Der ) const {
  derive(Der);
}

void function::derive( function &Der ) const {
}*/

std::ostream & operator<<( std::ostream &Stream, const function &Func ) {
  Func.print(Stream);
  return Stream;
}

} // End of 'adv_math' namespace
