#pragma once

#include <iostream>

#include "../vector.h"

namespace adv_math {
namespace equations {

class solution {
public:
  enum class status {
    SOLVED, ALL_R, EMPTY
  };
private:
  vector Roots;
  status Status;
  friend std::ostream & operator<<( std::ostream &, const solution & );

public:
  solution( const vector &Roots ) : Roots(Roots), Status(status::SOLVED) {
  }

  solution( status Stat ) : Status(Stat) {
  }

  const vector & getRoots( void ) {
    return Roots;
  }

  status getStatus( void ) {
    return Status;
  }
};

inline std::ostream & operator<<( std::ostream &Stream, const solution &Sol ) {
  switch (Sol.Status) {
  case solution::status::SOLVED:
    Stream << "{ ";
    for (const auto &it : Sol.Roots)
      Stream << it << "; ";
    Stream << "}";
    break;

  case solution::status::ALL_R:
    Stream << "(-INF; +INF)";
    break;

  case solution::status::EMPTY:
    Stream << "No solution";
    break;
  }
  return Stream;
}

template<class eq_t>
class solver {
protected:
  mutable int Iterations;
  mutable double Complexity;

public:
  virtual solution solve( const eq_t &ToSolve ) const = 0;
};

} // End of 'equations' namespace
} // End of 'adv_math' namespace
