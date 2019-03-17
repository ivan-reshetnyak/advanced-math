#include "stdafx.h"

#include <cmath>
#include <fstream>

#include "polynomial.h"

namespace adv_math {
namespace func {

int polynomial::size( void ) {
  return Members.size();
}

polynomial::polynomial( const std::initializer_list<double> &Powers ) {
  int i = 0;
  for (const auto &it : Powers) {
    Members[i] = it;
    i++;
  }
}

polynomial::polynomial( const std::map<int, double> &Powers ) : Members(Powers) {
}

polynomial::polynomial( const std::string &FileName ) {
  std::ifstream file;
  int p;
  double v;

  file.open(FileName);
  if (!file)
    return;

  while (file >> p >> v)
    operator[](p) = v;

  file.close();
}

double & polynomial::operator[]( int Power ) {
  auto it = Members.find(Power);
  if (it == Members.end())
    Members[Power] = 0;
  return Members[Power];
}

double polynomial::at( double X ) const {
  double y = 0;

  for (auto &i : Members)
    y += i.second * pow(X, i.first);

  return y;
}

double polynomial::deriveAt( double X ) const {
  double df = 0;

  for (auto &i : Members)
    if (i.first > 0)
      df += i.first * i.second * pow(X, i.first - 1);

  return df;
}

polynomial polynomial::derivative( void ) const {
  polynomial Res;
  derivative(Res);
  return Res;
}

void polynomial::derivative( polynomial &Der ) const {
  Der.Members.clear();

  for (auto &i : Members)
    if (i.first > 0)
      Der.Members[i.first - 1] = i.first * i.second;
}

void polynomial::print( std::ostream &Stream ) const {
  for (auto i = Members.crbegin(); i != Members.crend(); i++) {
    if (i->second != 0) {
      if (i != Members.crbegin())
        Stream << " + ";
      if (i->second != 1)
        Stream << i->second;
      if (i->first != 0) {
        Stream << "x";
        if (i->first != 1)
          Stream << "^" << i->first;
      }
    }
  }
}

} // End of 'funch' namespace
} // End of 'adv_math' namespace
