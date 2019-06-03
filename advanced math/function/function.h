#pragma once

#include "../stdafx.h"

#include "../definitions.h"

namespace adv_math {

class function {
private:
  double f( double X ) const;
  friend std::ostream & operator<<( std::ostream &Stream, const function &Func );

public:
  double operator()( double X ) const;
  double derive( double X ) const;
  //void derivative( function &Der ) const;
  std::vector<double> operator()( const std::initializer_list<double> &Points ) const;
  std::vector<double> operator()( const std::vector<double> &Points ) const;

protected:
  virtual void print( std::ostream &Stream ) const = 0;
  virtual double at( double X ) const = 0;
  virtual double deriveAt( double X ) const;
  //virtual void derive( function &Der ) const;
};

/*
template<class der_func>
class derivable : public function {
public:
  typedef der_func derivative_t;
  der_func derivative( void ) const {
    return _derivative();
  }

protected:
  virtual der_func _derivative( void ) const = 0;
};
*/

#define derived_from_function(template_class) \
  class = typename std::enable_if<std::is_base_of_v<function, template_class>>::type

} // End of 'adv_math' namespace
