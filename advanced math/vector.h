#pragma once

#include "stdafx.h"

namespace adv_math {

template<class type>
class vec : public std::vector<type> {
private:
  friend std::ostream & operator<<( std::ostream &, const vec & );

public:
  vec( void ) {
  }

  vec( const std::vector<type> &Vec ) : std::vector<type>(Vec) {
  }

  vec( int Size, type Val = 0 ) : std::vector<type>(Size, Val) {
  }

  vec( const std::initializer_list<type> & IL ) : std::vector<type>(IL) {
  }
};

using vector = vec<double>;

template<class type>
std::ostream & operator<<( std::ostream &Stream, const vec<type> &Vec ) {
  for (const auto &it : Vec)
    Stream << it << " ";
  return Stream;
}

inline std::ostream & operator<<( std::ostream &Stream, const vector &Vec ) {
  for (const auto &it : Vec)
    Stream << it << " ";
  return Stream;
}


} // End of 'adv_math' namespace
